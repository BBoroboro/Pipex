/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:00:15 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/08 15:31:42 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	control_args_nbr(int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("Error: wrong amount of argument\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	control_args_nbr_bonus(int ac, char **av)
{
	char	*str;

	str = "here_doc";
	if (ac == 1 || (ft_strcmp(av[1], str) == 0))
	{
		if (ac < 6)
		{
			ft_putstr_fd("Error: wrong amount of argument\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (ac < 5)
		{
			ft_putstr_fd("Error: wrong amount of argument\n", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

void	append_slash(t_data *data)
{
	int		i;
	char	*tmp;

	if (!data || !data->env)
	{
		ft_exit_error(data, "Environment");
		return ;
	}
	i = 0;
	while (data->env[i])
	{
		tmp = ft_strjoin(data->env[i], "/");
		if (!tmp)
			ft_exit_error(data, "Malloc");
		free(data->env[i]);
		data->env[i] = tmp;
		i++;
	}
}
