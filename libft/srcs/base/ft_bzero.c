/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:02 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/10 17:42:24 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int     main(void)
{

        int     array[] = {54, 85, 20, 63, 21};
        size_t  size = 3;
        int     length;

        for (length=0; length<5; length++) 
        {
                printf("%d", array[length]);
        }
        printf("\n");

        ft_bzero(array, size);

        for (length=0; length<5; length++) 
        {
                printf("%d", array[length]);
        }
        printf("\n");
    
        return (0);
}*/
