/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:58:58 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/08 11:05:05 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// last malloc check, 27 mars

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	control_args_nbr_bonus(ac, av);
	init_pipex_bonus(av, ac, &data, envp);
	forking(&data, av);
	return (0);
}
