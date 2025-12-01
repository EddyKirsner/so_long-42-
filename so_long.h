/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:30:44 by ekirsner          #+#    #+#             */
/*   Updated: 2024/10/30 16:13:14 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct position
{
	int	x;
	int	y;
}	t_pos;

typedef struct draws
{
	void	*coin;
	void	*exit;
	void	*player;
	void	*wall;
	void	*floor;
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		mov_count;
	t_pos	po;
}	t_img;

void	print_error(int error, char **map, char *str, int nb_line);

void	update_map(t_img *game, t_pos current);

void	printmap(char **map, void *mlx_ptr, void *win_ptr, int nb_line);

void	normiprout(char **map, t_img stock, int nb_line);

int		check_collected(char **map, int nb_line);

void	printmap2(char **map, t_img stock, int nb_line, t_pos ij);

int		close_window(t_img *game);

void	so_long_base(char **contener, int nb_line);

char	**allow_mem_map(char **contener, int nb_lines);

void	copy_map(char **contener, char **copy, int nb_lines);

int		count_line(int fd);

void	start_pos(char **contener, t_pos *position, int nb_line);

int		check_way(char **map, t_pos position, int nb_line);

void	ft_flood_fill(char **map, t_pos limit, t_pos cur);

int		ft_str_len(char *str);

void	init_zero(int *nb, int *nb2);

void	free_map(char **map, int nb_line);

int		check_wall(char **contener, int nb_line);

int		check_empty_item(char **contener, int nb_line);

int		check_item(char **contener, int nb_line, int j);

int		check_forbidden(char **contener, int nb_line);

#endif