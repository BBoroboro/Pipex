/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:38:43 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/16 15:33:40 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((*s1 == '\0' && *s2 == '\0') || n == 0)
		return (0);
	while (*s1 == *s2 && *s1 && --n)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
int	main(void)
{
	char *s1 = "salut";
	char *s2 = "sal~";
	char *s3 = "";

	printf("%d\n", ft_strncmp(s1, s2, 4));
	printf("%d\n", ft_strncmp(s1, s2, 3));
	printf("%d\n", ft_strncmp(s1, s2, 2));
	printf("%d\n", ft_strncmp(s1, s3, 4));
	printf("%d\n", ft_strncmp(s2, s3, 4));
	
	return (0);
}*/
