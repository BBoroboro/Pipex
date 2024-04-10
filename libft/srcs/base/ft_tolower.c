/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:57:36 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/08 16:50:33 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
int	main(void)
{
	int	a;
	int	b;

	int	c;
	int	d;

	a = 'e';
	b = 'e';

	c = 'E';
	d = 'E';

	printf("%d\n", ft_tolower(a));
	printf("%d\n", tolower(b));
	printf("%d\n", ft_tolower(c));
	printf("%d\n", tolower(d));

	return (0);
}*/
