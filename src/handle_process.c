/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:05:24 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/08 15:17:07 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(t_data *data)
{
	int		status;
	int		i;
	pid_t	exit_pid;

	i = 0;
	while (i < data->cmd_nbr)
	{
		exit_pid = waitpid(data->pid[i], &status, 0);
		if (exit_pid == -1)
			perror("Waitpid");
		i++;
	}
	ft_free_all(data);
	exit(WEXITSTATUS(status));
}

void	child_process(t_data *data, char **av, int i)
{
	if (i == 0 && data->here_doc == 0)
		open_infile(data, av);
	dup2(data->pfd_in[i], STDIN_FILENO);
	if (i == data->cmd_nbr - 1)
		open_outfile(data, av);
	dup2(data->pfd_out[i], STDOUT_FILENO);
	close_pipe(data);
	find_cmd_path(data, i);
	execve(data->cmds[i]->cmd_path, data->cmds[i]->tab, data->envp);
	perror("execve");
	exit(EXIT_SUCCESS);
}
