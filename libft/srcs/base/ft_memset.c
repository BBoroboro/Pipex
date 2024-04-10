/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:23:05 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/15 15:56:14 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = (unsigned char)c;
		str++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{

	int	array[] = {54, 85, 20, 63, 21};
	size_t	size = 5;
	int	length;

	for (length=0; length<5; length++) 
	{
		printf("%d", array[length]);
	}
	printf("\n");

	ft_memset(array, 0, size);

	for (length=0; length<5; length++) 
	{
		printf("%d", array[length]);
	}
	printf("\n");
    
	return (0);
}*/
