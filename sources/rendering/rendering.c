#include <cub.h>
#include <macro.h>
#include <raycast.h>
#include <math.h>
#include <minimap.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WALL_HEIGHT 800

int	ft_atoi_base(char *str, int base)
{
    int	result;
    int	sign;
    int	i;

    result = 0;
    sign = 1;
    i = 0;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            result = result * base + (str[i] - '0');
        else if (str[i] >= 'a' && str[i] <= 'f')
            result = result * base + (str[i] - 'a' + 10);
        else if (str[i] >= 'A' && str[i] <= 'F')
            result = result * base + (str[i] - 'A' + 10);
        else
            break;
        i++;
    }
    return (result * sign);
}

static void	init_keys(t_cub *data)
{
    data->keys.w = 0;
    data->keys.s = 0;
    data->keys.a = 0;
    data->keys.d = 0;
    data->keys.left = 0;
    data->keys.right = 0;
}

static void	init_window_info(mlx_window_create_info *info)
{
    *info = (mlx_window_create_info){0};
    info->title = "Cub3D";
    info->width = WINDOW_WIDTH;
    info->height = WINDOW_HEIGHT;
}

static void	window_hook_3d(int event, void *param)
{
    t_cub	*data;

    data = (t_cub *)param;
    if (event == 0)
        mlx_loop_end(*data->mlx);
}

static void	key_press_hook_3d(int key, void *param)
{
    t_cub	*data;

    data = (t_cub *)param;
    if (key == 41)
        mlx_loop_end(*data->mlx);
}

// Nouvelle fonction de conversion des couleurs
static unsigned int convert_rgb_str_to_color(char *rgb_str)
{
    int r, g, b;
    char **split;
    unsigned int color;

    split = ft_split(rgb_str, ',');
    if (!split || !split[0] || !split[1] || !split[2])
        return (0xFF000000); // Noir en cas d'erreur

    r = ft_atoi(split[0]);
    g = ft_atoi(split[1]);
    b = ft_atoi(split[2]);

    // Libérer la mémoire des split
    int i = 0;
    while (split[i])
        lp_free(split[i++]);
    lp_free(split);

    // Créer la couleur RGBA (alpha à 255)
    color = ((r & 0xFF) << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) | 0xFF;

    return color;
}

// Ajoutez cette structure pour stocker les textures chargées
typedef struct s_textures
{
    mlx_image   no;
    mlx_image   so;
    mlx_image   we;
    mlx_image   ea;
    int         width;
    int         height;
} t_textures;

// Fonction pour charger les textures
static t_textures load_textures(mlx_context mlx, t_cub *data)
{
    t_textures textures;
    int img_width, img_height;

	printf("ici: %s\n", data->no);

	// Charger les quatre textures (nord, sud, est, ouest)
    textures.no = mlx_new_image_from_file(mlx, data->no, &img_width, &img_height);
    textures.so = mlx_new_image_from_file(mlx, data->so, &img_width, &img_height);
    textures.we = mlx_new_image_from_file(mlx, data->we, &img_width, &img_height);
    textures.ea = mlx_new_image_from_file(mlx, data->ea, &img_width, &img_height);

    textures.width = img_width;
    textures.height = img_height;

    printf("Textures chargées: %p, %p, %p, %p\n",
           (void*)textures.no, (void*)textures.so,
           (void*)textures.we, (void*)textures.ea);
    printf("Dimensions des textures: %d x %d\n", textures.width, textures.height);

    return textures;
}

// Modifier la fonction draw_vertical_line pour utiliser les textures
static void draw_vertical_line(mlx_context mlx, mlx_window win,
                              int x, int wall_height, t_textures *textures,
                              double wall_x, int wall_orientation, t_cub *data)
{
    int         start;
    int         end;
    int         y;
    mlx_color   ceiling_color;
    mlx_color   floor_color;
    mlx_color   texture_color;
    double      tex_pos;
    double      step;
    int         tex_y;
    int         tex_x;
    mlx_image   current_texture;

    // Convertir les chaînes RGB en valeurs de couleur
    ceiling_color.rgba = convert_rgb_str_to_color(data->ceiling);
    floor_color.rgba = convert_rgb_str_to_color(data->floor);

    // Calculer la position x dans la texture (dépend de wall_x)
    tex_x = (int)(wall_x * textures->width);
    if (tex_x < 0)
        tex_x = 0;
    if (tex_x >= textures->width)
        tex_x = textures->width - 1;

    // Sélectionner la texture en fonction de l'orientation du mur
    switch (wall_orientation)
    {
        case 0: // Nord
            current_texture = textures->no;
            break;
        case 1: // Est
            current_texture = textures->ea;
            break;
        case 2: // Sud
            current_texture = textures->so;
            break;
        case 3: // Ouest
            current_texture = textures->we;
            break;
        default:
            current_texture = textures->no; // Par défaut
    }

    start = (WINDOW_HEIGHT - wall_height) / 2;
    if (start < 0)
        start = 0;
    end = start + wall_height;
    if (end > WINDOW_HEIGHT)
        end = WINDOW_HEIGHT;

    // Calcul pour le mappage de texture
    step = (double)textures->height / wall_height;
    tex_pos = (start - (WINDOW_HEIGHT - wall_height) / 2) * step;

    // Dessiner le plafond
    y = 0;
    while (y < start)
    {
        mlx_pixel_put(mlx, win, x, y, ceiling_color);
        y++;
    }

    // Dessiner le mur avec la texture, sans effet d'ombrage
    y = start;
    while (y < end)
    {
        tex_y = (int)tex_pos & (textures->height - 1);
        tex_pos += step;

        // Obtenir la couleur du pixel dans la texture sans modification
        texture_color = mlx_get_image_pixel(mlx, current_texture, tex_x, tex_y);

        // Appliquer directement la couleur de la texture sans effet d'ombrage
        mlx_pixel_put(mlx, win, x, y, texture_color);
        y++;
    }

    // Dessiner le sol, sans effet de dégradé
    y = end;
    while (y < WINDOW_HEIGHT)
    {
        mlx_pixel_put(mlx, win, x, y, floor_color);
        y++;
    }
}

// Modifier la fonction render_3d_view pour utiliser les textures
static void render_3d_view(mlx_context mlx, mlx_window win, t_cub *data, t_textures *textures)
{
    int         i;
    double      angle;
    double      base_angle;
    t_vector    intersection;
    int         hit;
    double      distance;
    int         wall_height;
    int         nb_rayons;
    double      correction_factor;
    double      distance_adjusted;
    int         wall_orientation;
    double      wall_x; // Coordonnée x du point d'impact sur le mur (pour le mappage de texture)

    base_angle = get_base_angle(get_player_orientation(data));
    nb_rayons = WINDOW_WIDTH;

    i = 0;
    while (i < nb_rayons)
    {
        // Calcul plus précis de l'angle pour chaque rayon
        angle = base_angle - (FOV / 2.0) + (i * FOV / (double)(nb_rayons - 1));

        // Normaliser l'angle
        while (angle < 0)
            angle += 360.0;
        while (angle >= 360.0)
            angle -= 360.0;

        // Calculer l'intersection avec le rayon
        ray_cast(data->player, angle, &hit, &intersection);

        if (hit)
        {
            // Calculer la distance euclidienne
            distance = sqrt(pow(data->player->pos.x - intersection.x, 2) +
                        pow(data->player->pos.y - intersection.y, 2));

            // Corriger l'effet fisheye avec le cosinus de l'angle relatif (en radians)
            double relative_angle = fabs((angle - base_angle) * M_PI / 180.0);
            correction_factor = cos(relative_angle);
            distance_adjusted = distance * correction_factor;

            // Déterminer l'orientation du mur et la coordonnée x sur le mur
            double x_diff = intersection.x - data->player->pos.x;
            double y_diff = intersection.y - data->player->pos.y;

            // Déterminer si c'est un mur horizontal ou vertical avec plus de précision
            // Utiliser une comparaison plus stricte pour déterminer le type de mur
            if (fabs(intersection.x - round(intersection.x)) < 0.001)  // Plus précis
            {
                // Mur vertical (Est/Ouest)
                wall_orientation = (x_diff > 0) ? 1 : 3; // 1 = Est, 3 = Ouest
                wall_x = intersection.y - floor(intersection.y); // position relative y
            }
            else if (fabs(intersection.y - round(intersection.y)) < 0.001) // Ajout d'une condition explicite
            {
                // Mur horizontal (Nord/Sud)
                wall_orientation = (y_diff > 0) ? 2 : 0; // 2 = Sud, 0 = Nord
                wall_x = intersection.x - floor(intersection.x); // position relative x
            }
            else
            {
                // En cas de doute, choisir en fonction de la distance à l'entier le plus proche
                if (fabs(intersection.x - round(intersection.x)) < fabs(intersection.y - round(intersection.y)))
                {
                    wall_orientation = (x_diff > 0) ? 1 : 3;
                    wall_x = intersection.y - floor(intersection.y);
                }
                else
                {
                    wall_orientation = (y_diff > 0) ? 2 : 0;
                    wall_x = intersection.x - floor(intersection.x);
                }
            }

            // Hauteur du mur à l'écran
            wall_height = (int)((WALL_HEIGHT / (distance_adjusted + 0.0001)) * (WINDOW_HEIGHT / 1080.0));

            // Limiter la hauteur maximale pour éviter les murs trop grands
            if (wall_height > WINDOW_HEIGHT * 3)
                wall_height = WINDOW_HEIGHT * 3;

            // Dessiner la ligne verticale avec texture
            draw_vertical_line(mlx, win, i, wall_height, textures, wall_x, wall_orientation, data);
        }
        i++;
    }
}

// Modifier la fonction d'initialisation du rendu 3D
void init_3d_rendering(t_cub *data)
{
    mlx_context             mlx;
    mlx_window_create_info  info;
    mlx_window              win;
    t_textures              textures;

    mlx = mlx_init();
    init_keys(data);
    init_window_info(&info);
    data->mlx = &mlx;
    win = mlx_new_window(*data->mlx, &info);
    data->win = &win;

    // Charger les textures
    textures = load_textures(mlx, data);

    // Rendu 3D initial avec textures
    render_3d_view(mlx, win, data, &textures);

    mlx_set_fps_goal(mlx, 60);

    // Installation des hooks pour les événements
    mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook_3d, data);
    mlx_on_event(mlx, win, MLX_KEYDOWN, key_press_hook_3d, data);

    // Démarrer la boucle principale
    mlx_loop(mlx);

    // Libérer les ressources des textures à la fin
    mlx_destroy_image(mlx, textures.no);
    mlx_destroy_image(mlx, textures.so);
    mlx_destroy_image(mlx, textures.we);
    mlx_destroy_image(mlx, textures.ea);
}
