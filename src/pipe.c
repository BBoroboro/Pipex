/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:55:45 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/04 11:04:21 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_pipe(t_data *data)
{
	int	i;
	int	fd_tmp[2];

	i = 0;
	while (i < data->cmd_nbr - 1)
	{
		if (pipe(fd_tmp) == -1)
			ft_exit_error(data, "Pipe");
		data->pfd_out[i] = fd_tmp[WRITE];
		data->pfd_in[i + 1] = fd_tmp[READ];
		i++;
	}
}

void	close_pipe(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return ;
	while (i < data->cmd_nbr)
	{
		if (data->pfd_in && data->pfd_in[i] != -1)
		{
			close(data->pfd_in[i]);
			data->pfd_in[i] = -1;
		}
		if (data->pfd_out && data->pfd_out[i] != -1)
		{
			close(data->pfd_out[i]);
			data->pfd_out[i] = -1;
		}
		i++;
	}
}
