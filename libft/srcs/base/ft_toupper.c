/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:47:41 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/08 16:49:34 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
}
/*
int	main(void)
{
	int	c;
	int	d;

	c = 'e';
	d = 'e';

	printf("%d\n", ft_toupper(c));
	printf("%d\n", toupper(d));

	return (0);
}*/
