/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_maj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:06:26 by mamoulin          #+#    #+#             */
/*   Updated: 2023/11/28 16:12:58 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_lenhex_maj(unsigned int nb)
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

void	ft_convhex_maj(unsigned int nb)
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
		ft_convhex_maj(nbr / 16);
	if ((nbr % 16) < 10)
		temp = nbr % 16 + '0';
	else
		temp = nbr % 16 + 'A' - 10;
	write(1, &temp, 1);
}

int	ft_printhex_maj(unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_convhex_maj(nb);
	return (ft_lenhex_maj(nb));
}
