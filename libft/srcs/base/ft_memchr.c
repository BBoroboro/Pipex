/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:56:26 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/09 11:34:43 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	c = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)str + i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const void	*str = "J ai faim et je ne vais pas pouvoir manger";
	int	c = 112;
	size_t	n = 60;
	char	*sn;
	char	*sb;

	sn = ft_memchr(str, c, n);
	sb = memchr(str, c, n);

	printf("%s\n", sn);
	printf("%s\n", sb);

	return (0);

}*/
