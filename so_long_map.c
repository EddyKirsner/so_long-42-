/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:27:31 by ekirsner          #+#    #+#             */
/*   Updated: 2024/10/30 16:01:15 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int nb_line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j != nb_line)
	{
		free(map[j]);
		j++;
	}
	free(map);
	map = NULL;
}

int	check_wall(char **contener, int nb_line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (contener[0][i])
		if (contener[0][i++] != '1')
			return (1);
	j = i - 1;
	i = 0;
	while (contener[nb_line - 1][i])
		if (contener[nb_line - 1][i++] != '1')
			return (1);
	i = 0;
	while (i != nb_line)
	{
		if (contener[i][0] != '1' || contener[i][j] != '1' ||
			contener[i][j + 1] != 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_empty_item(char **contener, int nb_line)
{
	int	i;
	int	player;
	int	coin;
	int	exit;
	int	j;

	j = 0;
	init_zero(&player, &coin);
	init_zero(&exit, &i);
	while (j != nb_line)
	{
		while (contener[j][i])
		{
			if (contener[j][i] != '1' && contener[j][i] != 'F' &&
				contener[j][i] != '0')
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	check_item(char **contener, int nb_line, int j)
{
	int	i;
	int	player;
	int	coin;
	int	exit;

	init_zero(&player, &coin);
	init_zero(&exit, &i);
	while (j != nb_line)
	{
		while (contener[j][i])
		{
			if (contener[j][i] == 'E')
				exit++;
			if (contener[j][i] == 'C')
				coin++;
			if (contener[j][i] == 'P')
				player++;
			i++;
		}
		i = 0;
		j++;
	}
	if (exit == 1 && coin && player == 1)
		return (0);
	return (1);
}

int	check_forbidden(char **contener, int nb_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j != nb_line)
	{
		while (contener[j][i])
		{
			if (contener[j][i] != 'C' && contener[j][i] != 'E'
				&& contener[j][i] != 'P' && contener[j][i] != '0'
					&& contener[j][i] != '1')
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
