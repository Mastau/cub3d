#include <cub.h>
#include <macro.h>
#include <raycast.h>
#include <math.h>
#include <minimap.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WALL_HEIGHT 600

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
        free(split[i++]);
    free(split);

    // Créer la couleur RGBA (alpha à 255)
    color = ((r & 0xFF) << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) | 0xFF;

    return color;
}

// Modifier la fonction draw_vertical_line
static void draw_vertical_line(mlx_context mlx, mlx_window win,
                               int x, int wall_height, int color_value, t_cub *data)
{
    int         start;
    int         end;
    int         y;
    mlx_color   ceiling_color;
    mlx_color   floor_color;
    mlx_color   wall_color;
    double      shade_factor;

    // Convertir les chaînes RGB en valeurs de couleur
    ceiling_color.rgba = convert_rgb_str_to_color(data->ceiling);
    floor_color.rgba = convert_rgb_str_to_color(data->floor);
    wall_color.rgba = color_value;    // Couleur du mur de base

    start = (WINDOW_HEIGHT - wall_height) / 2;
    if (start < 0)
        start = 0;
    end = start + wall_height;
    if (end > WINDOW_HEIGHT)
        end = WINDOW_HEIGHT;

    // Dessiner le plafond
    y = 0;
    while (y < start)
    {
        mlx_pixel_put(mlx, win, x, y, ceiling_color);
        y++;
    }

    // Dessiner le mur avec un effet de dégradé vertical
    y = start;
    while (y < end)
    {
        // Calculer un facteur d'ombrage basé sur la position verticale
        shade_factor = 1.0 - fabs(((double)(y - start) / wall_height) - 0.5) * 0.5;

        // Appliquer le facteur d'ombrage à la couleur
        mlx_color shaded_color;
        shaded_color.r = wall_color.r * shade_factor;
        shaded_color.g = wall_color.g * shade_factor;
        shaded_color.b = wall_color.b * shade_factor;
        shaded_color.a = wall_color.a;

        mlx_pixel_put(mlx, win, x, y, shaded_color);
        y++;
    }

    // Dessiner le sol
    y = end;
    while (y < WINDOW_HEIGHT)
    {
        // Effet de dégradé pour le sol (plus foncé au loin)
        double floor_shade = 1.0 - ((double)(y - end) / (WINDOW_HEIGHT - end)) * 0.3;

        mlx_color shaded_floor;
        shaded_floor.r = floor_color.r * floor_shade;
        shaded_floor.g = floor_color.g * floor_shade;
        shaded_floor.b = floor_color.b * floor_shade;
        shaded_floor.a = floor_color.a;

        mlx_pixel_put(mlx, win, x, y, shaded_floor);
        y++;
    }
}

static void	render_3d_view(mlx_context mlx, mlx_window win, t_cub *data)
{
    int			i;
    double		angle;
    double		base_angle;
    t_vector	intersection;
    int			hit;
    double		distance;
    int			wall_height;
    int			nb_rayons;
    int			color;
    double      correction_factor;
    double      distance_adjusted;
    int         wall_orientation;

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

            // Déterminer l'orientation du mur avec plus de précision
            double x_diff = intersection.x - data->player->pos.x;
            double y_diff = intersection.y - data->player->pos.y;


            // Déterminer si c'est un mur horizontal ou vertical
            if (fabs(intersection.x - round(intersection.x)) < 0.01)
            {
                // Mur vertical (Est/Ouest)
                wall_orientation = (x_diff > 0) ? 1 : 3; // 1 = Est, 3 = Ouest
            }
            else
            {
                // Mur horizontal (Nord/Sud)
                wall_orientation = (y_diff > 0) ? 2 : 0; // 2 = Sud, 0 = Nord
            }

            // Amélioration de la formule de hauteur du mur pour un rendu plus cohérent
            wall_height = (int)((WALL_HEIGHT / (distance_adjusted + 0.0001)) * (WINDOW_HEIGHT / 1080.0));

            // Limiter la hauteur maximale pour éviter les murs trop grands
            if (wall_height > WINDOW_HEIGHT * 3)
                wall_height = WINDOW_HEIGHT * 3;

            // Courbe d'atténuation plus douce pour la distance
            double intensity = 1.0 / (1.0 + distance_adjusted * 0.15);

            // Déterminer la couleur de base selon l'orientation du mur
            switch (wall_orientation)
            {
                case 0: // Nord
                    color = 0x00FF00FF; // Vert
                    break;
                case 1: // Est
                    color = 0xDD2222FF; // Rouge foncé
                    break;
                case 2: // Sud
                    color = 0x00DD22FF; // Vert foncé
                    break;
                case 3: // Ouest
                    color = 0xFF0000FF; // Rouge
                    break;
                default:
                    color = 0xFFFFFFFF; // Blanc (ne devrait pas arriver)
            }

            // Appliquer l'intensité à la couleur
            mlx_color base_color;
            base_color.rgba = color;

            mlx_color adjusted_color;
            adjusted_color.r = base_color.r * intensity;
            adjusted_color.g = base_color.g * intensity;
            adjusted_color.b = base_color.b * intensity;
            adjusted_color.a = base_color.a;

            // Dessiner la ligne verticale représentant une tranche du mur
            draw_vertical_line(mlx, win, i, wall_height, adjusted_color.rgba, data);
        }
        i++;
    }
}

void	init_3d_rendering(t_cub *data)
{
    mlx_context				mlx;
    mlx_window_create_info	info;
    mlx_window				win;

    mlx = mlx_init();
    init_keys(data);
    init_window_info(&info);
    data->mlx = &mlx;
    win = mlx_new_window(*data->mlx, &info);
    data->win = &win;

    // Rendu 3D initial (statique)
    render_3d_view(mlx, win, data);

    mlx_set_fps_goal(mlx, 60);

    // Installation des hooks pour les événements
    mlx_on_event(mlx, win, MLX_WINDOW_EVENT, window_hook_3d, data);
    mlx_on_event(mlx, win, MLX_KEYDOWN, key_press_hook_3d, data);

    // Démarrer la boucle principale
    mlx_loop(mlx);
}
