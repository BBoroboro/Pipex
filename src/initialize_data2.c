/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:16:30 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/08 15:26:24 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pfd(t_data *data)
{
	data->pfd_in = ft_calloc((data->cmd_nbr) + 1, sizeof(int));
	if (!data->pfd_in)
		ft_exit_error(data, "Malloc");
	ft_memset(data->pfd_in, -1, (data->cmd_nbr * sizeof(int)));
	data->pfd_out = ft_calloc((data->cmd_nbr) + 1, sizeof(int));
	if (!data->pfd_out)
		ft_exit_error(data, "Malloc");
	ft_memset(data->pfd_out, -1, (data->cmd_nbr * sizeof(int)));
}

void	init_pid(t_data *data)
{
	data->pid = ft_calloc((data->cmd_nbr) + 1, sizeof(pid_t));
	if (!data->pid)
		ft_exit_error(data, "Malloc");
}

void	init_here_doc(t_data *data, char **av)
{
	if (ft_strcmp(av[1], "here_doc") == 0)
		data->here_doc = 1;
	else
		data->here_doc = 0;
}

void	init_limiter(t_data *data, char **av)
{
	if (data->here_doc == 1)
	{
		data->limiter = ft_strdup(av[2]);
		if (!data->limiter)
			ft_exit_error(data, "Malloc");
	}
}

void	init_envp(t_data *data, char **envp)
{
	if (!envp[0])
		data->envp = NULL;
	else
		data->envp = envp;
}
