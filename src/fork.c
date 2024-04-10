/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:55:53 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/08 15:16:17 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	forking(t_data *data, char **av)
{
	int	i;

	if (data->here_doc == 1)
		ft_here_doc(data);
	open_pipe(data);
	i = 0;
	while (i < data->cmd_nbr)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			ft_exit_error(data, "Fork");
		else if (data->pid[i] == 0)
			child_process(data, av, i);
		i++;
	}
	close_pipe(data);
	parent_process(data);
}
