/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:11:38 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/11 16:32:26 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_neg(int nb, int fd)
{
	write(1, "-", fd);
	nb = -(nb);
	return (nb);
}

int	ft_pchar_fd(char c, int fd)
{
	write(1, &c, fd);
	return (1);
}
