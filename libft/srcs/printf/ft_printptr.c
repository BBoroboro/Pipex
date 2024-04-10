/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:14:36 by mamoulin          #+#    #+#             */
/*   Updated: 2023/12/06 16:53:14 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_ptr_len(size_t ptr)
{
	size_t	i;

	i = 0;
	while (ptr)
	{
		i++;
		ptr /= 16;
	}
	return (i);
}

void	ft_display_ptr(size_t ptr)
{
	if (ptr >= 16)
	{
		ft_display_ptr(ptr / 16);
		ft_display_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_printptr(size_t ptr)
{
	int	res;

	res = 0;
	if (ptr == 0)
	{
		res += write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		res += write(1, "0x", 2);
		ft_display_ptr(ptr);
		res += ft_ptr_len(ptr);
	}
	return (res);
}
/*
int	main(void)
{
	long	var = 42;
	size_t	ptr;

	ptr = &var;
	ft_printptr(ptr);
	printf("%ld", ptr);
}*/
