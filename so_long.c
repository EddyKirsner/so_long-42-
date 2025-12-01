/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:19:55 by ekirsner          #+#    #+#             */
/*   Updated: 2024/10/30 16:38:36 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_img *game)
{
	t_pos	current;

	current.x = game->po.x;
	current.y = game->po.y;
	if (keycode == 65307)
		close_window(game);
	if (keycode == 97 && (game->map)[game->po.y][game->po.x - 1] != '1')
		game->po.x--;
	if (keycode == 100 && (game->map)[game->po.y][game->po.x + 1] != '1')
		game->po.x++;
	if (keycode == 119 && (game->map)[game->po.y - 1][game->po.x] != '1')
		game->po.y--;
	if (keycode == 115 && (game->map)[game->po.y + 1][game->po.x] != '1')
		game->po.y++;
	if (current.x != game->po.x || current.y != game->po.y)
	{
		update_map(game, current);
		game->mov_count++;
		ft_printf("%d\n", game->mov_count);
	}
	printmap(game->map, game->mlx_ptr, game->win_ptr, game->y / 32);
	return (0);
}

int	launcher(char **map, int x, int y)
{
	t_img	game;

	game.mov_count = 0;
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, x, y, "So_Long");
	if (!game.mlx_ptr || !game.win_ptr)
		close_window(&game);
	game.map = map;
	game.y = y;
	game.coin = 0;
	game.exit = 0;
	game.player = 0;
	game.floor = 0;
	game.wall = 0;
	game.x = 0;
	game.po.x = 0;
	game.po.y = 0;
	start_pos(map, &game.po, y / 32);
	printmap(map, game.mlx_ptr, game.win_ptr, y / 32);
	mlx_hook(game.win_ptr, 17, 0, close_window, &game);
	mlx_key_hook(game.win_ptr, handle_key, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

void	ft_strcpy(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str2[i] && str2[i] != '\n')
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}

void	ft_copy_allow(int nb_lines, char **contener, int fd)
{
	int		i;
	char	*copy;

	i = 0;
	while (i != nb_lines)
	{
		copy = get_next_line(fd);
		contener[i] = malloc(sizeof(char) * (ft_str_len(copy) + 1));
		ft_strcpy(contener[i], copy);
		free(copy);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		nb_lines;
	char	**contener;

	i = 0;
	if (argc != 2)
		print_error(1, NULL, NULL, 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(3, NULL, NULL, 0);
	nb_lines = count_line(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	contener = malloc(sizeof(char *) * (nb_lines));
	if (!contener)
		return (1);
	ft_copy_allow(nb_lines, contener, fd);
	i = 0;
	while (contener[0][i])
		i++;
	so_long_base(contener, nb_lines);
	if (i > 100 || nb_lines > 25)
		print_error(2, contener, NULL, nb_lines);
	launcher(contener, i * 32, nb_lines * 32);
}
