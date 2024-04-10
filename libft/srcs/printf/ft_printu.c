/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:34:00 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/28 13:43:56 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_num_len(unsigned int nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
	{
		len++;
	}
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int nb)
{
	char	*res;
	size_t	len;

	len = ft_num_len(nb);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (nb)
	{
		res[len - 1] = nb % 10 + 48;
		len--;
		nb = nb / 10;
	}
	return (res);
}

int	ft_printu(unsigned int nb)
{
	int		print_res;
	char	*res;

	print_res = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		res = ft_uitoa(nb);
		print_res += ft_printstr(res);
		free(res);
	}
	return (print_res);
}
/*
int	main(void)
{
	unsigned int	u;

	u = 4294967295;
	ft_printu(u);
	return (0);
}*/
