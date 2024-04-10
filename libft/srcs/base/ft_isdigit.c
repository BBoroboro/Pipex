/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:09:11 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/20 16:34:03 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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

		c = '9';
		d = '9';

		e = '~';
		f = '~';

		printf("%d\n", ft_isdigit(c));
		printf("%d\n", isdigit(d));
		printf("%d\n", ft_isdigit(e));
		printf("%d\n", isdigit(f));

		return (0);
}*/
