/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:58:09 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/02 15:51:10 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_open_infile(char *infile);
static void	ft_first_child(char *infile, t_cmd cmd);

void	ft_first_fork(t_cmd cmd, char *infile)
{
	pid_t	pid;
	int		wstatus;

	pid = fork();
	if (pid == -1)
	{
		close(cmd.write);
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		ft_first_child(infile, cmd);
	}
	else
	{
		close(cmd.write);
		wait(&wstatus);
	}
}

static void	ft_first_child(char *infile, t_cmd cmd)
{
	int	fd;

	fd = ft_open_infile(infile);
	if (fd == -1)
	{
		close(cmd.write);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, 0) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd.write, 1) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	execve(cmd.pathname, cmd.arg, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

static int	ft_open_infile(char *infile)
{
	int	fd;

	if (access(infile, X_OK) != 0)
	{
		ft_printf("zsh: permission denied: %s\n", infile);
		return (-1);
	}
	if (access(infile, R_OK) != 0)
	{
		ft_printf("zsh: no such file or directory: %s\n", infile);
		return (-1);
	}
	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	return (fd);
}
