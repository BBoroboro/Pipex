/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:07:50 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/08 19:20:34 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*concatenate_path(t_data *data, int i, int n)
{
	char	*path;

	if (!(regular_path(data->cmds[n]->tab[0])))
	{
		path = ft_strjoin(data->env[i], data->cmds[n]->tab[0]);
		if (!path)
			ft_exit_error(data, "Malloc");
	}
	else
	{
		path = ft_strdup(data->cmds[n]->tab[0]);
		if (!path)
			ft_exit_error(data, "Malloc");
	}
	return (path);
}

static void	error_path(t_data *data, int n)
{
	ft_putstr_fd(data->cmds[n]->tab[0], 2);
	if (!regular_path(data->cmds[n]->tab[0]))
		ft_putstr_fd(": command not found\n", 2);
	else
		perror(" ");
	ft_free_all(data);
	exit(127);
}

static void	check_cmd(t_data *data)
{
	ft_free_all(data);
	ft_putstr_fd(" : command not found\n", 2);
	exit(127);
}

void	find_cmd_path(t_data *data, int n)
{
	int		i;
	char	*path;

	data->cmds[n]->cmd_path = NULL;
	i = -1;
	while ((data->env && data->env[++i]) || regular_path(data->cmds[n]->tab[0]))
	{
		if (data->cmds[n]->tab[0] == NULL)
			check_cmd(data);
		path = concatenate_path(data, i, n);
		if (!path)
			ft_exit_error(data, "Malloc");
		if (access(path, F_OK) == 0)
		{
			data->cmds[n]->cmd_path = ft_strdup(path);
			free(path);
			if (!data->cmds[n]->cmd_path)
				ft_exit_error(data, "Malloc");
			path_permission(data, n);
			break ;
		}
		free(path);
	}
	if (!data->cmds[n]->cmd_path)
		error_path(data, n);
}

void	path_permission(t_data *data, int n)
{
	if (access(data->cmds[n]->cmd_path, X_OK) == -1)
	{
		perror(data->cmds[n]->cmd_path);
		close_pipe(data);
		ft_free_all(data);
		exit(126);
	}
}
