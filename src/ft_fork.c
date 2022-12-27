/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:40:22 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/26 16:22:28 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_set_pipe_kid(t_cmd *cmd, int i, int argc);
static void	ft_set_pipe_parent(t_cmd *cmd, int i, int argc);

void	ft_fork(int argc, t_cmd *cmd)
{
	int		i;
	pid_t	pid;
	int		wstatus;

	i = 0;
	while (i <= argc - 2)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_set_pipe_kid(cmd, i, argc);
			//write(2, cmd[i].pathname, ft_strlen(cmd[i].pathname));
			execve(cmd[i].pathname, cmd[i].arg, NULL);
			perror("execve");
			break ;
		}
		else
		{
			ft_set_pipe_parent(cmd, i, argc);
			wait(&wstatus);
			if (WIFEXITED(wstatus))
			{
				 if (WEXITSTATUS(wstatus))
					break ;
			}
			i++;
		}
	}
}

//set the pipe for kid
//close th epipe for parent
inline void	ft_set_pipe_kid(t_cmd *cmd, int i, int argc)
{
	if (i != 0)
	{
		dup2(*(cmd[i].read_pipe), 0);
		close(*(cmd[i].read_pipe));
	}
	if (i != argc - 2)
	{
		dup2(*(cmd[i].write_pipe), 1);
		close(*(cmd[i].write_pipe));
	}
}

inline void	ft_set_pipe_parent(t_cmd *cmd, int i, int argc)
{
	if (i != 0)
		close(*(cmd[i].read_pipe));
	if (i != argc - 2)
		close(*(cmd[i].write_pipe));
}
