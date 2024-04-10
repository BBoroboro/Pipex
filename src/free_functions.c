/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:15:16 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/03 17:16:04 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_all(t_data *data)
{
	if (data->cmds)
		ft_free_cmd(data);
	if (data->env)
		ft_free_env(data);
	if (data->pfd_in)
		free(data->pfd_in);
	if (data->pfd_out)
		free(data->pfd_out);
	if (data->pid)
		free(data->pid);
	if (data->limiter)
		free(data->limiter);
}

void	ft_exit_error(t_data *data, char *err_mess)
{
	close_pipe(data);
	perror(err_mess);
	ft_free_all(data);
	exit(EXIT_FAILURE);
}

void	ft_free_cmd(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmds[i])
	{
		free(data->cmds[i]->cmd_path);
		ft_free_tab(data->cmds[i]->tab);
		free(data->cmds[i]);
		i++;
	}
	free(data->cmds);
}

void	ft_free_env(t_data *data)
{
	ft_free_tab(data->env);
}
