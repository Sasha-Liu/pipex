/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:25:22 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/04 15:32:21 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_open_infile(char *infile);

void	ft_first_child(t_cmd *cmd)
{
	int		fd;
	char	*infile;

	infile = cmd[0].file;
	fd = ft_open_infile(infile);
	if (fd == -1)
	{
		close(cmd[0].write);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, 0) == -1)
	{
		perror("in first child : dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd[0].write, 1) == -1)
	{
		perror("in first child : dup2");
		exit(EXIT_FAILURE);
	}
	execve(cmd[0].pathname, cmd[0].arg, NULL);
	ft_printf_err(cmd[0].arg[0], ": command not found\n");
	exit(EXIT_FAILURE);
}

static int	ft_open_infile(char *infile)
{
	int	fd;

	if (access(infile, F_OK) != 0)
	{
		ft_printf("zsh: no such file or directory: %s\n", infile);
		return (-1);
	}
	if (access(infile, R_OK) != 0)
	{
		ft_printf("zsh: permission denied: %s\n", infile);
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
