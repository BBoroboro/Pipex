/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:06:27 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/20 11:41:02 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char			*dest;
// 	unsigned int	len;
// 	size_t			i;
// 	size_t			j;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
// 	dest = malloc(sizeof(char) * len);
// 	if (!dest)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		dest[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		dest[i + j] = s2[j];
// 		j++;
// 	}
// 	dest[i + j] = '\0';
// 	return (dest);
// }

/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*res;

	s1 = "j ai tres tres ";
	s2 = "tres faim...";
	res = ft_strjoin(s1, s2);
	printf("%s\n", res);

	return (0);
}*/
char	*ft_strjoin(char *s1, char *s2)
{
	char			*dest;
	unsigned int	len;
	size_t			i;
	size_t			j;

	if (!s1)
		s1 = "";
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (free(s1), free(s2), NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	j = -1;
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	return (dest);
}
