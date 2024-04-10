/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:32:40 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/16 15:35:07 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int	main(void)
{
	unsigned char	c;
	unsigned char	d;
	unsigned char	e;
	unsigned char	f;

	c = 'a';
	d = 'a';

	e = '~';
	f = '~';

	printf("%d\n", ft_isalpha(c));
	printf("%d\n", isalpha(d));
	printf("%d\n", ft_isalpha(e));
	printf("%d\n", isalpha(f));

	return (0);
}*/
