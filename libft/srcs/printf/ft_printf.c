/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:12:08 by mamoulin          #+#    #+#             */
/*   Updated: 2023/12/15 14:36:37 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_format(const char format, va_list args)
{
	int	res;

	res = 0;
	if (format == '%')
		res += ft_printpc();
	else if (format == 's')
		res += ft_printstr(va_arg(args, char *));
	else if (format == 'c')
		res += ft_printchar(va_arg(args, int));
	else if (format == 'u')
		res += ft_printu(va_arg(args, unsigned int));
	else if (format == 'p')
		res += ft_printptr(va_arg(args, size_t));
	else if (format == 'd' || format == 'i')
		res += ft_print_nbr(va_arg(args, int));
	else if (format == 'x')
		res += ft_print_hex(va_arg(args, unsigned int));
	else if (format == 'X')
		res += ft_printhex_maj(va_arg(args, unsigned int));
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		res;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += ft_format(str[i + 1], args);
			i++;
		}
		else
			res += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (res);
}
/*
int	main(void)
{
	int	i;

	i = 42;
	ft_printf("%d", i);
	return (0);
}*/
