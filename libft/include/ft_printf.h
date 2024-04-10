/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:54:03 by mamoulin          #+#    #+#             */
/*   Updated: 2023/12/13 17:09:27 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printpc(void);
int	ft_print_nbr(int n);
int	ft_printu(unsigned int nb);
int	ft_print_hex(unsigned int nb);
int	ft_printhex_maj(unsigned int nb);
int	ft_printptr(uintptr_t ptr);
int	ft_printf(const char *str, ...);

#endif
