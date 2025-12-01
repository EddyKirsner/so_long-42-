/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:19:21 by ekirsner          #+#    #+#             */
/*   Updated: 2024/10/29 19:56:34 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int error, char **map, char *str, int nb_line)
{
	if (map)
		free_map(map, nb_line);
	if (str)
		free(str);
	if (error == 1)
		ft_printf("error : expected format -> (./_so_long map.ber)\nexit...\n");
	if (error == 2)
		write(2, "error : invalid map.\nexit...\n", 30);
	if (error == 3)
		write(2, "error : file uncorrectly opened, retry please\n", 45);
	if (error == 4)
		write(2, "error : walls uncorrectly setted\n", 33);
	if (error == 5)
		write(2, "error : items uncorrectly puted\n", 32);
	exit(EXIT_FAILURE);
}
