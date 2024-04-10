/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:09:07 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/20 15:06:34 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(long n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_malloc(char *res, size_t len)
{
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	return (res);
}

char	*ft_fill_char(char *res, long nb, size_t len, size_t sign)
{
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
		sign = 1;
	}
	res[len] = '\0';
	while (len > sign)
	{
		res[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	size_t	sign;
	long	nb;

	nb = (long)n;
	res = NULL;
	sign = 0;
	len = ft_intlen(nb);
	res = ft_malloc(res, len);
	if (!res)
		return (NULL);
	res = ft_fill_char(res, nb, len, sign);
	return (res);
}
/*
int	main(void)
{
	int	n = -1;

	printf("%s\n", ft_itoa(n));
	return (0);
}*/
