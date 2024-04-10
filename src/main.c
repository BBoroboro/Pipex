/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:00:11 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/08 15:16:33 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	control_args_nbr(ac);
	init_pipex(av, ac, &data, envp);
	forking(&data, av);
	return (0);
}
