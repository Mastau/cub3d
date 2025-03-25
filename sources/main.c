// #include "cub.h"
// #include "fcntl.h"
// #include "libft.h"
// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	int		fd;
// 	t_cub	*data;
// 	int		i;

// 	if (ac != 2)
// 		return (1);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_putstr_fd("Error: Can't open file\n", 2);
// 		return (1);
// 	}
// 	data = parsing_data(fd);
// 	close(fd);
// 	if (!data)
// 		return (1);
// 	if (map_fill(data))
// 		return (1);
// 	i = 0;
// 	while (data->map[i])
// 	{
// 		printf("%s\n", data->map[i]);
// 		i++;
// 	}
// 	free(data);

#include <cub.h>
#include <debug.h>
#include <rendering.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_cub		*data;
	t_player	player;
	int		fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Can't open file\n", 2);
		return (1);
	}
	data = parsing_data(fd);
	close(fd);
	if (!data)
		return (1);
	if (map_fill(data))
		return (1);
	initialize_player(&player, data);
	data->player = &player;
	init_3d_rendering(data);
	free_cub(data);
	return (0);
}
