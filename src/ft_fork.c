/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:24:20 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/04 14:04:57 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//n is the size of cmd array
void	ft_fork(t_cmd *cmd, int n)
{
	pid_t	pid;
	int		i;
	int		wstatus;

	i = 0;
	while (i < n)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_child(cmd, n, i);
		}
		else
		{
			ft_parent(cmd, n, i);
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		wait(&wstatus);
		i++;
	}
}

void	ft_parent(t_cmd *cmd, int n, int i)
{
	if (i == 0)
	{
		close(cmd[i].write);
	}
	else if (i == n - 1)
	{
		close(cmd[i]. read);
	}
	else
	{
		close(cmd[i].write);
		close(cmd[i].read);
	}
}

void	ft_child(t_cmd *cmd, int n, int i)
{
	if (i == 0)
		ft_first_child(cmd);
	else if (i == n - 1)
		ft_last_child(cmd, n);
	else
		ft_middle_child(cmd, i);
}
