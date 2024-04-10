/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:00:11 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/20 18:09:48 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_hex(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_conv_hex(unsigned int nb)
{
	long	nbr;
	int		temp;

	nbr = nb;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 16)
		ft_conv_hex(nbr / 16);
	if ((nbr % 16) < 10)
		temp = nbr % 16 + '0';
	else
		temp = nbr % 16 + 'a' - 10;
	write(1, &temp, 1);
}

int	ft_print_hex(unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_conv_hex(nb);
	return (ft_len_hex(nb));
}
/*
int	main(void)
{
	ft_print_hex(1, 'X');
	return (0);
}*/
