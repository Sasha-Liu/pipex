/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:58:28 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/02 11:50:06 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_open_outfile(char *outfile);
static void	ft_last_child(char *outfile, t_cmd cmd);

void	ft_last_fork(t_cmd cmd, char *outfile)
{
	pid_t	pid;
	int		wstatus;

	pid = fork();
	if (pid == 0)
	{
		ft_last_child(outfile, cmd);
	}
	else
	{
		close(cmd.read);
		wait(&wstatus);
	}
}

static void	ft_last_child(char *outfile, t_cmd cmd)
{
	int	fd;

	fd = ft_open_outfile(outfile);
	if (fd == -1)
		return ;
	if (dup2(cmd.read, 0) == -1)
	{
		perror("dup2");
		return ;
	}
	if (dup2(fd, 1) == -1)
	{
		perror("dup2");
		return ;
	}
	execve(cmd.pathname, cmd.arg, NULL);
	perror("execve");
}

static int	ft_open_outfile(char *outfile)
{
	int	fd;

	fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	return (fd);
}
