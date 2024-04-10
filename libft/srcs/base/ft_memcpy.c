/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:12:55 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/20 09:57:35 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;

	if (!dest && !src)
		return (NULL);
	dst = (char *)dest;
	i = 0;
	while (i < n)
	{
		*dst = (*(char *)src);
		dst++;
		src++;
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char str[] = "memcpy test!";
	char str1[30];
	char str2[30];

	ft_memcpy(str1, str, strlen(str)+1);
	ft_memcpy(str2, "copy", 5);
	printf("str: %s\nstr1 : %s\nstr2: %s\n",str,str1,str2);
	return (0);
}*/
