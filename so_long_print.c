/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:20:12 by ekirsner          #+#    #+#             */
/*   Updated: 2024/10/30 16:04:28 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printmap2(char **map, t_img stock, int nb_line, t_pos ij)
{
	while (nb_line && ij.x < nb_line)
	{
		while (map[ij.x][ij.y])
		{
			if (map[ij.x][ij.y] == '1')
				mlx_put_image_to_window(stock.mlx_ptr,
					stock.win_ptr, stock.wall, ij.y * 32, ij.x * 32);
			if (map[ij.x][ij.y] == '0')
				mlx_put_image_to_window(stock.mlx_ptr,
					stock.win_ptr, stock.floor, ij.y * 32, ij.x * 32);
			if (map[ij.x][ij.y] == 'P')
				mlx_put_image_to_window(stock.mlx_ptr,
					stock.win_ptr, stock.player, ij.y * 32, ij.x * 32);
			if (map[ij.x][ij.y] == 'C')
				mlx_put_image_to_window(stock.mlx_ptr,
					stock.win_ptr, stock.coin, ij.y * 32, ij.x * 32);
			if (map[ij.x][ij.y] == 'E')
				mlx_put_image_to_window(stock.mlx_ptr,
					stock.win_ptr, stock.exit, ij.y * 32, ij.x * 32);
			ij.y++;
		}
		ij.y = 0;
		ij.x++;
	}
}

int	check_collected(char **map, int nb_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != nb_line)
	{
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

void	normiprout(char **map, t_img stock, int nb_line)
{
	t_pos	ij;

	ij.x = 0;
	ij.y = 0;
	if (!(stock.player) || !stock.wall
		|| !stock.exit || !stock.coin || !stock.floor)
	{
		if (stock.coin)
			mlx_destroy_image(stock.mlx_ptr, stock.coin);
		if (stock.player)
			mlx_destroy_image(stock.mlx_ptr, stock.player);
		if (stock.exit)
			mlx_destroy_image(stock.mlx_ptr, stock.exit);
		if (stock.wall)
			mlx_destroy_image(stock.mlx_ptr, stock.wall);
		if (stock.floor)
			mlx_destroy_image(stock.mlx_ptr, stock.floor);
		mlx_destroy_window(stock.mlx_ptr, stock.win_ptr);
		mlx_destroy_display(stock.mlx_ptr);
		free_map(map, nb_line);
		free(stock.mlx_ptr);
		exit(0);
	}
	printmap2(map, stock, nb_line, ij);
}

void	printmap(char **map, void *mlx_ptr, void *win_ptr, int nb_line)
{
	int		img_w;
	int		img_h;
	t_pos	position;
	t_img	s;

	s.mlx_ptr = mlx_ptr;
	s.win_ptr = win_ptr;
	start_pos(map, &position, nb_line);
	img_w = 32;
	img_h = 32;
	s.coin = mlx_xpm_file_to_image(mlx_ptr, "s/b.xpm", &img_w, &img_h);
	if (check_collected(map, nb_line))
		s.player = mlx_xpm_file_to_image(mlx_ptr, "s/p.xpm", &img_w, &img_h);
	else
		s.player = mlx_xpm_file_to_image(mlx_ptr, "s/g.xpm", &img_w, &img_h);
	s.exit = mlx_xpm_file_to_image(mlx_ptr, "s/e.xpm", &img_w, &img_h);
	s.wall = mlx_xpm_file_to_image(mlx_ptr, "s/w.xpm", &img_w, &img_h);
	s.floor = mlx_xpm_file_to_image(mlx_ptr, "s/f.xpm", &img_w, &img_h);
	normiprout(map, s, nb_line);
	mlx_destroy_image(mlx_ptr, s.coin);
	mlx_destroy_image(mlx_ptr, s.player);
	mlx_destroy_image(mlx_ptr, s.exit);
	mlx_destroy_image(mlx_ptr, s.wall);
	mlx_destroy_image(mlx_ptr, s.floor);
}

void	update_map(t_img *game, t_pos current)
{
	char	**map_a;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map_a = game->map;
	if (map_a[current.y][current.x] != 'E')
		map_a[current.y][current.x] = '0';
	if (map_a[game->po.y][game->po.x] == 'C')
		map_a[game->po.y][game->po.x] = 'P';
	if (map_a[game->po.y][game->po.x] == '0')
		map_a[game->po.y][game->po.x] = 'P';
	if (map_a[game->po.y][game->po.x] == 'E')
	{
		if (check_collected(map_a, game->y / 32))
			close_window(game);
	}
}
