/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:06:22 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/20 11:06:06 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	index;
	size_t	i;

	if (!dest && size == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen(dest);
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	index = 0;
	while (dest[index])
		index++;
	i = 0;
	while (src[i] && (i + index + 1) < (size))
	{
		dest[index + i] = src[i];
		i++;
	}
	dest[index + i] = '\0';
	return (ft_strlen(src) + dst_len);
}
