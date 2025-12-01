/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:31:14 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/11 16:38:45 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h> 
# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_countnbr(int nbr);

int	ft_isupper(int c);

int	ft_pstr_fd(char *str, int fd);

int	ft_putnbr_unsigned(unsigned int n);

int	ft_pchar_fd(char c, int fd);

int	ft_printf(const char *content, ...);

int	convert_neg(int nb, int fd);

#endif