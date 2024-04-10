/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:16:05 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/20 14:24:19 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp_big;
	char	*temp_little;

	if (!big && !len)
		return (NULL);
	i = 0;
	temp_big = (char *)big;
	temp_little = (char *)little;
	if (!ft_strlen(temp_little) || temp_little[i] == '\0')
		return (temp_big);
	while (temp_big[i] && i < len)
	{
		j = 0;
		while ((temp_big[i + j] == temp_little[j] && i + j < len)
			|| temp_little[j] == '\0')
		{
			if (temp_little[j] == '\0')
				return (temp_big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *str = "J ai super faim moi jefais comment
	? J ai faim mais j ai pas d argent";
	const char *str1 = " je fais";
	const char *str2 = "super faim";
	const char *str3 = "super faim";
	const char *str4 = "super plein";
	const char *str5 = "faim mais";
	const char *str6 = "";

	printf("%s\n", ft_strnstr(str, str1, 50));
	printf("%s\n", ft_strnstr(str, str2, 50));
	printf("%s\n", ft_strnstr(str, str3, 4));
	printf("%s\n", ft_strnstr(str, str4, 50));
	printf("%s\n", ft_strnstr(str, str5, 50));
	printf("%s\n", ft_strnstr(str, str6, 50));

	printf("\n");

	printf("%s\n", strnstr(str, str1, 50));
	printf("%s\n", strnstr(str, str2, 50));
	printf("%s\n", strnstr(str, str3, 11));
	printf("%s\n", strnstr(str, str4, 50));
	printf("%s\n", strnstr(str, str5, 50));
	printf("%s\n", strnstr(str, str6, 50));

	return (0);
}*/
