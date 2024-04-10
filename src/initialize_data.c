/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:16:52 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/08 18:47:01 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(char **av, int ac, t_data *data, char **envp)
{
	init_envp(data, envp);
	stock_path(envp, data);
	init_cmd_nbr(data, ac);
	init_cmd(av, data);
	init_pfd(data);
	init_pid(data);
}

void	init_pipex_bonus(char **av, int ac, t_data *data, char **envp)
{
	init_envp(data, envp);
	stock_path(envp, data);
	init_here_doc(data, av);
	init_limiter(data, av);
	init_cmd_nbr(data, ac);
	init_cmd(av, data);
	init_pfd(data);
	init_pid(data);
}

void	init_cmd_tab(int n, t_data *data)
{
	data->cmds[n]->tab = ft_split(data->cmds[n]->cmd_line, ' ');
	if (!data->cmds[n]->tab)
		ft_exit_error(data, "Malloc");
}

void	init_cmd(char **av, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 2 + data->here_doc;
	data->cmds = ft_calloc(data->cmd_nbr + 1, sizeof(t_cmd *));
	if (!data->cmds)
		ft_exit_error(data, "Malloc");
	while (i < data->cmd_nbr)
	{
		data->cmds[i] = ft_calloc(1, sizeof(t_cmd));
		if (!data->cmds[i])
			ft_exit_error(data, "Malloc");
		data->cmds[i]->cmd_line = av[j];
		i++;
		j++;
	}
	i = 0;
	while (i < data->cmd_nbr)
	{
		init_cmd_tab(i, data);
		i++;
	}
}

void	init_cmd_nbr(t_data *data, int ac)
{
	data->cmd_nbr = ac - 3 - data->here_doc;
}
