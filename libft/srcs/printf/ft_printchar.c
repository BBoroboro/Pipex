/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:53:46 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/20 18:11:01 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	if (c == 0)
	{
		write(1, "\0", 1);
		return (1);
	}
	else
		write(1, &c, 1);
	return (1);
}
/*
int	main(void)
{
	ft_printchar('\0');
	ft_printchar('1');
	ft_printchar(1);
	return (0);
}*/
