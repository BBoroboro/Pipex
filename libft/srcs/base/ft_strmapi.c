/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:17:30 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/30 11:26:16 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
char	ft_upper(unsigned int i, char str)
{
	i = 0;

	return (str - 32);
}

int	main(void)
{
	char	str[15] = "jaifaimfrero";
	char	*dest;

	dest = ft_strmapi(str, ft_upper);
	printf("%s\n", dest);
	return (0);
}*/
