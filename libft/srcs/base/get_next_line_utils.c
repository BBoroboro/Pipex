/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:32:20 by mamoulin          #+#    #+#             */
/*   Updated: 2023/12/13 15:56:47 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memcpy(void *dest, void *src, size_t n)
// {
// 	size_t	i;
// 	char	*dst;

// 	if (!dest && !src)
// 		return (NULL);
// 	dst = (char *)dest;
// 	i = 0;
// 	while (i < n)
// 	{
// 		*dst = (*(char *)src);
// 		dst++;
// 		src++;
// 		i++;
// 	}
// 	return (dest);
// }

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

char	*ft_clean_stash(char *str)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == 0 || str[i + 1] == 0)
	{
		free(str);
		return (NULL);
	}
	i++;
	new_stash = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_stash)
		return (free(str), NULL);
	while (str[i])
		new_stash[j++] = str[i++];
	new_stash[j] = '\0';
	free(str);
	return (new_stash);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		else
			i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (0);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char			*dest;
// 	unsigned int	len;
// 	size_t			i;
// 	size_t			j;

// 	if (!s1)
// 		s1 = "";
// 	if (!s1 && !s2)
// 		return (NULL);
// 	len = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	dest = malloc(sizeof(char) * len);
// 	if (!dest)
// 		return (free(s1), free(s2), NULL);
// 	i = -1;
// 	while (s1[++i])
// 		dest[i] = s1[i];
// 	j = -1;
// 	while (s2[++j])
// 		dest[i + j] = s2[j];
// 	dest[i + j] = '\0';
// 	return (dest);
// }
