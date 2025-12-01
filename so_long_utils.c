/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:32:45 by ekirsner          #+#    #+#             */
/*   Updated: 2024/10/30 16:01:12 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(int fd)
{
	char	*str;
	int		i;

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL && i == 0)
			print_error(2, NULL, NULL, 0);
		if (str == NULL)
			return (i);
		free(str);
		i++;
	}
}

void	copy_map(char **contener, char **copy, int nb_lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != nb_lines)
	{
		while (contener[j][i])
		{
			copy[j][i] = contener[j][i];
			i++;
		}
		copy[j][i] = '\0';
		i = 0;
		j++;
	}
}

char	**allow_mem_map(char **contener, int nb_lines)
{
	int		i;
	int		j;
	char	**copy;

	j = 0;
	i = 0;
	while (contener[j][i])
		i++;
	copy = malloc(sizeof(char *) * nb_lines);
	if (!copy)
		return (NULL);
	while (j != nb_lines)
	{
		copy[j] = malloc(sizeof(char) * (i + 1));
		if (!copy[j])
			return (NULL);
		j++;
	}
	copy_map(contener, copy, nb_lines);
	return (copy);
}

void	so_long_base(char **contener, int nb_line)
{
	int		j;
	t_pos	position;
	char	**copy;

	position.x = 0;
	position.y = 0;
	j = 0;
	if (check_wall(contener, nb_line))
		return (print_error(4, contener, NULL, nb_line));
	if (check_item(contener, nb_line, j))
		return (print_error(5, contener, NULL, nb_line));
	if (check_forbidden(contener, nb_line))
		return (print_error(2, contener, NULL, nb_line));
	copy = allow_mem_map(contener, nb_line);
	start_pos(copy, &position, nb_line);
	if (check_way(copy, position, nb_line))
	{
		free_map(copy, nb_line);
		return (print_error(2, contener, NULL, nb_line));
	}
	free_map(copy, nb_line);
}

int	close_window(t_img *game)
{
	if (game->coin)
		mlx_destroy_image(game->mlx_ptr, game->coin);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free_map(game->map, game->y / 32);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}
