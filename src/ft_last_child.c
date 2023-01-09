/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:26:26 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/09 12:16:07 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_open_outfile(char *outfile);

void	ft_last_child(t_cmd *cmd, int n)
{
	int		fd;
	char	*outfile;

	outfile = cmd[n - 1].file;
	fd = ft_open_outfile(outfile);
	if (dup2(cmd[n - 1].read, 0) == -1)
	{
		perror("in last child: first : dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, 1) == -1)
	{
		perror("in last child: second : dup2");
		exit(EXIT_FAILURE);
	}
	execve(cmd[n - 1].pathname, cmd[n - 1].arg, NULL);
	if (ft_strncmp(cmd[n - 1].arg[0], "", 1) == 0)
		write(2, "zsh: permission denied:\n", 25);
	else
		ft_printf_err("zsh: command not found:", cmd[n - 1].arg[0]);
	exit(EXIT_FAILURE);
}

static int	ft_open_outfile(char *outfile)
{
	int	fd;

	if (ft_strncmp(outfile, "", 1) == 0)
	{
		write(2, "zsh: no such file or directory:\n", 32);
		exit(EXIT_FAILURE);
	}
	if (access(outfile, F_OK) == 0 && access(outfile, W_OK) != 0)
	{
		ft_printf("zsh: permission denied: %s\n", outfile);
		exit(EXIT_FAILURE);
	}
	fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
