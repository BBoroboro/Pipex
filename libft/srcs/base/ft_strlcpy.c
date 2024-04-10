/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:36:17 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/10 16:31:24 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char	*src1 = "J ai mal a la tete";
	char	dest1[50];

	char	*src2 = "J ai mal a la tete";
	char	dest2[50];

	printf("%zu\n", ft_strlcpy(dest1, src1, 0));
	printf("%zu\n", strlcpy(dest2, src2, 0));

	printf("%s\n", dest1);
	printf("%s\n", dest2);

	return (0);
}*/
