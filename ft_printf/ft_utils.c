/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:49:34 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/11 16:30:51 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_countnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr > 0)
	{
		while (nbr > 0)
		{
			nbr /= 10;
			i++;
		}
	}
	else
	{
		i += 2;
		while (nbr < -9)
		{
			nbr /= 10;
			i++;
		}
	}
	return (i);
}

int	ft_isupper(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	ft_pstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_pchar_fd((n % 10) + '0', 1);
	return (count);
}
