/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:35:35 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/27 20:59:36 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_open_outfile(char *outfile);
static int	ft_open_infile(char *infile);

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
			dup2(cmd[i].read, 0);
			dup2(cmd[i].write, 1);
			execve(cmd[i].pathname, cmd[i].arg, NULL);
			perror("execve");
			break ;
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

void	ft_last_fork(t_cmd cmd, char *outfile)
{
	int		fd;
	pid_t	pid;
	int		wstatus;

	fd = ft_open_outfile(outfile);
	if (fd == -1)
		return ;
	pid = fork();
	if (pid == 0)
	{
		dup2(cmd.read, 0);
		dup2(fd, 1);
		execve(cmd.pathname, cmd.arg, NULL);
		perror("execve");
		return ;
	}
	else
	{
		close(cmd.read);
		close(fd);
		wait(&wstatus);
	}
	return ;
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

void	ft_first_fork(t_cmd cmd, char *infile)
{
	int		fd;
	pid_t	pid;
	int		wstatus;

	fd = ft_open_infile(infile);
	if (fd == -1)
	{
		close(cmd.write);
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, 0);
		dup2(cmd.write, 1);
		execve(cmd.pathname, cmd.arg, NULL);
		perror("execve");
		return ;
	}
	else
	{
		close(cmd.write);
		close(fd);
		wait(&wstatus);
	}
}

static int	ft_open_infile(char *infile)
{
	int	fd;

	if (access(infile, R_OK) != 0)
	{
		ft_printf("No such file or directory: %s\n", infile);
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
