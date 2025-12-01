/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:20:04 by ekirsner          #+#    #+#             */
/*   Updated: 2024/10/29 19:53:56 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_zero(int *nb, int *nb2)
{
	*nb = 0;
	*nb2 = 0;
}

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_flood_fill(char **map, t_pos limit, t_pos cur)
{
	if (cur.x < 0 || cur.x >= limit.x || cur.y < 0
		|| cur.y >= limit.y
		|| (map[cur.y][cur.x] != '0' && map[cur.y][cur.x] != 'P'
		&& map[cur.y][cur.x] != 'C' && map[cur.y][cur.x] != 'E'))
		return ;
	map[cur.y][cur.x] = 'F';
	ft_flood_fill(map, limit, (t_pos){cur.x + 1, cur.y});
	ft_flood_fill(map, limit, (t_pos){cur.x - 1, cur.y});
	ft_flood_fill(map, limit, (t_pos){cur.x, cur.y + 1});
	ft_flood_fill(map, limit, (t_pos){cur.x, cur.y - 1});
}

int	check_way(char **map, t_pos position, int nb_line)
{
	t_pos	limit;
	int		exit;

	exit = 0;
	limit.x = ft_str_len(map[0]) - 1;
	limit.y = nb_line - 1;
	ft_flood_fill(map, limit, position);
	if (check_empty_item(map, nb_line))
		return (1);
	return (0);
}

void	start_pos(char **contener, t_pos *position, int nb_line)
{
	int	i;
	int	j;

	init_zero(&i, &j);
	while (j != nb_line)
	{
		while (contener[j][i])
		{
			if (contener[j][i] == 'P')
			{
				position->x = i;
				position->y = j;
			}
			i++;
		}
		i = 0;
		j++;
	}
}
