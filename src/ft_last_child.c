/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:26:26 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/05 15:41:37 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_last_child(t_cmd *cmd, int n)
{
	int		fd;
	char	*outfile;

	outfile = cmd[n - 1].file;
	fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
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
	ft_printf_err("zsh: command not found: ", cmd[n - 1].arg[0]);
	exit(EXIT_FAILURE);
}
