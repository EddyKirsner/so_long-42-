/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:24:00 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/11 16:28:52 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_super(int n, int fd)
{
	int	nb;
	int	nbr;

	nbr = n;
	if (nbr == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		nbr = convert_neg(nbr, 1);
		ft_putnbr_super(nbr, fd);
	}
	else
	{
		if (nbr > 9)
		{
			ft_putnbr_super(nbr / 10, fd);
			ft_putnbr_super(nbr % 10, fd);
		}
		else
		{
			nb = nbr + 48;
			write(fd, &nb, 1);
		}
	}
	return (ft_countnbr(n));
}

int	ft_puthex(unsigned long n, int maj)
{
	size_t	count;
	char	*hex_digits;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (maj == 1)
	{
		hex_digits = "0123456789ABCDEF";
	}
	if (n >= 16)
		count += ft_puthex(n / 16, maj);
	count += ft_pchar_fd(hex_digits[n % 16], 1);
	return (count);
}

static int	ft_hexpoint(unsigned long po)
{
	size_t	count;

	if (!po)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 2;
	write(1, "0x", 2);
	count += ft_puthex(po, 0);
	return (count);
}

static int	dispenser(const char *c, va_list args)
{
	if (*c == 'c')
		return (ft_pchar_fd(va_arg(args, int), 1));
	else if (*c == 's')
		return (ft_pstr_fd((char *)va_arg(args, const char *), 1));
	else if (*c == 'p')
		return (ft_hexpoint(va_arg(args, unsigned long)));
	else if (*c == 'd' || *c == 'i')
		return (ft_putnbr_super(va_arg(args, int), 1));
	else if (*c == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (*c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (*c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (*c == '%')
		return (write(1, "%", 1));
	else
		return (write(1, c, 1));
	return (0);
}

int	ft_printf(const char *content, ...)
{
	va_list		args;
	const char	*po;
	int			len;

	len = 0;
	if (!content)
		return (-1);
	po = content;
	va_start(args, content);
	while (*po)
	{
		if (*po == '%')
		{
			po++;
			len += dispenser(po, args);
		}
		else
			len += ft_pchar_fd(*po, 1);
		po++;
	}
	va_end(args);
	return (len);
}
/*
int main()
{
	//printf(" NULL %s NULL ", NULL);
    ft_printf("\n NULL %s NULL ", NULL);
    //printf(" %u ",3294967294);
    //ft_printf("%i",ft_printf("%d", -0));
    //ft_printf();
    return (0);
}
*/