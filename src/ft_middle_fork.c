/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:35:35 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/04 12:13:28 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_middle_child(t_cmd *cmd, int i);

void	ft_middle_fork(t_cmd *cmd, int argc)
{
	pid_t	pid;
	int		wstatus;
	int		i;

	i = 1;
	while (i < argc - 4)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_middle_child(cmd, i);
		}
		else
		{
			close(cmd[i].read);
			close(cmd[i].write);
			wait(&wstatus);
		}
		i++;
	}
}

static void	ft_middle_child(t_cmd *cmd, int i)
{
	if (dup2(cmd[i].read, 0) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd[i].write, 1) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	execve(cmd[i].pathname, cmd[i].arg, NULL);
	exit(EXIT_FAILURE);
}
