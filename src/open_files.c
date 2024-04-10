/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:01:12 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/08 19:08:01 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_here_doc(t_data *data, int *p_fd)
{
	char	*line;
	int		i;

	i = ft_strlen(data->limiter);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, data->limiter, i) == 0 && line[i] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, p_fd[WRITE]);
		free(line);
	}
	data->pfd_in[0] = p_fd[READ];
}

void	ft_here_doc(t_data *data)
{
	int	p_fd[2];

	if (pipe(p_fd) == -1)
		ft_exit_error(data, "Pipe");
	open_here_doc(data, p_fd);
	close(p_fd[WRITE]);
}

int	open_infile(t_data *data, char **av)
{
	data->pfd_in[0] = open(av[1], O_RDONLY);
	if (data->pfd_in[0] == -1)
	{
		ft_exit_error(data, av[1]);
	}
	if (access(av[1], R_OK) == -1)
		ft_exit_error(data, av[1]);
	return (0);
}

int	open_outfile(t_data *data, char **av)
{
	if (data->here_doc == 0)
		data->pfd_out[data->cmd_nbr - 1] = open(av[data->cmd_nbr
				+ data->here_doc + 2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (data->here_doc == 1)
		data->pfd_out[data->cmd_nbr - 1] = open(av[data->cmd_nbr
				+ data->here_doc + 2], O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (data->pfd_out[data->cmd_nbr - 1] == -1)
	{
		ft_exit_error(data, av[data->cmd_nbr + data->here_doc + 2]);
		return (1);
	}
	return (0);
}
