/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:13:45 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/08 18:31:56 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*scan_envp(char **envp, t_data *data)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			str = ft_strdup(envp[i] + 5);
			if (!str)
				ft_exit_error(data, "Malloc");
		}
		i++;
	}
	return (str);
}

void	stock_path(char **envp, t_data *data)
{
	char	*path_env;
	int		i;

	i = 0;
	path_env = NULL;
	path_env = scan_envp(envp, data);
	if (!path_env)
		return ;
	data->env = ft_split(path_env, ':');
	if (!data->env)
	{
		free(path_env);
		ft_exit_error(data, "Malloc");
	}
	free(path_env);
	append_slash(data);
}

int	regular_path(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '.' || str[i] == '/' || str[i] == '~')
		return (1);
	return (0);
}
