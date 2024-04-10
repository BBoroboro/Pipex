/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:48:07 by mamoulin          #+#    #+#             */
/*   Updated: 2024/04/08 18:35:36 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "ft_printf.h"
# include "libft.h"
# include <sys/wait.h>

# define READ 0
# define WRITE 1

typedef struct s_cmd
{
	char	*cmd_line;
	char	**tab;
	char	*cmd_path;
}			t_cmd;

typedef struct s_data
{
	int		cmd_nbr;
	int		here_doc;
	int		*pfd_in;
	int		*pfd_out;
	int		*hd_fd;
	pid_t	*pid;
	char	**env;
	char	*limiter;
	char	**envp;
	t_cmd	**cmds;
}			t_data;

// intialize data.c
void		init_pipex(char **av, int ac, t_data *data, char **envp);
void		init_pipex_bonus(char **av, int ac, t_data *data, char **envp);
void		init_cmd_tab(int n, t_data *data);
void		init_cmd(char **av, t_data *data);
void		init_cmd_nbr(t_data *data, int ac);
// initialize data2.c
void		init_pfd(t_data *data);
void		init_pid(t_data *data);
void		init_here_doc(t_data *data, char **av);
void		init_limiter(t_data *data, char **av);
void		init_envp(t_data *data, char **envp);

// path.c
void		find_cmd_path(t_data *data, int n);
void		path_permission(t_data *data, int n);
// path2.c
void		stock_path(char **envp, t_data *data);
int			regular_path(char *str);

// parsing.c
int			control_args_nbr(int ac);
int			control_args_nbr_bonus(int ac, char **av);
void		append_slash(t_data *data);

// open files.c
void		open_here_doc(t_data *data, int *p_fd);
void		ft_here_doc(t_data *data);
int			open_infile(t_data *data, char **av);
int			open_outfile(t_data *data, char **av);

// pipe.c
void		open_pipe(t_data *data);
void		close_pipe(t_data *data);

// fork.c
void		forking(t_data *data, char **av);

// free_functions.c
void		ft_free_all(t_data *data);
void		ft_exit_error(t_data *data, char *err_mess);
void		ft_free_cmd(t_data *data);
void		ft_free_env(t_data *data);

// handle_process.c
void		parent_process(t_data *data);
void		child_process(t_data *data, char **av, int i);

#endif