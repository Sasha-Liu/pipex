/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:58:28 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/02 15:54:24 by hsliu            ###   ########lyon.fr   */
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

	fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd.read, 0) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, 1) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	execve(cmd.pathname, cmd.arg, NULL);
	perror("execve");
	exit("EXIT_FAILURE");
}
