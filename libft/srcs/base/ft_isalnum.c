/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:10:08 by mamoulin          #+#    #+#             */
/*   Updated: 2024/01/23 10:34:59 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)))
		return (1);
	return (0);
}
/*
int	main(void)
{
		unsigned char   c;
		unsigned char   d;
		unsigned char   e;
		unsigned char   f;

	c = 'a';
	d = '(';
	e = '9';
	f = '~';

		printf("%d\n", ft_isalnum(c));
		printf("%d\n", isalnum(c));
		printf("%d\n", ft_isalnum(d));
		printf("%d\n", isalnum(d));
		printf("%d\n", ft_isalnum(e));
		printf("%d\n", isalnum(e));
		printf("%d\n", ft_isalnum(f));
		printf("%d\n", isalnum(f));

		return (0);
}*/
