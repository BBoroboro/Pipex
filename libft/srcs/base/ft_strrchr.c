/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:52:16 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/13 16:37:12 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s + ft_strlen((char *)s);
	while (*str != (char)c)
	{
		if (str == s)
			return (NULL);
		str--;
	}
	return (str);
}
/*
int     main(void)
{
        const char *str = "j ai faim.mais .je tiens. le coup";
        const char ch = '.';
        char *ret;

        ret = ft_strrchr(str, ch);

        printf("String after |%c| is - |%s|\n", ch, ret);

        const char *str1 = "j ai faim.mais .je tiens. le coup";
        const char ch1 = '.';
        char *ret1;

        ret1 = strrchr(str1, ch1);

        printf("String after |%c| is - |%s|\n", ch1, ret1);


        return (0);

}*/
