/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:33:59 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/26 14:20:13 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free_rdwr(int argc, t_cmd *cmd)
{
	free(cmd[0].pathname);
	free(cmd[0].arg[0]);
	free(cmd[0].arg[1]);
	free(cmd[0].arg);
	free(cmd[argc - 2].pathname);
	free(cmd[argc - 2].arg[0]);
	free(cmd[argc - 2].arg[1]);
	free(cmd[argc - 2].arg);
}

void	ft_free_arg(int argc, t_cmd *cmd)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 2)
	{
		j = 0;
		while (cmd[i].arg[j])
		{
			free(cmd[i].arg[j]);
			j++;
		}
		free(cmd[i].arg);
		i++;
	}
}

void	ft_free_pathname(int argc, t_cmd *cmd)
{
	int	i;

	i = 1;
	while (i < argc - 2)
	{
		free(cmd[i].pathname);
		i++;
	}
}

void	ft_free_pipe(int **pipefd, int argc)
{
	int	i;

	if (pipefd == NULL)
		return ;
	i = 0;
	while (i < argc - 2)
	{
		free(pipefd[i]);
		i++;
	}
	free(pipefd);
}

void	ft_free_cmd(int argc, t_cmd *cmd, int **pipefd)
{
	ft_free_pipe(pipefd, argc);
	ft_free_pathname(argc, cmd);
	ft_free_arg(argc, cmd);
	ft_free_rdwr(argc, cmd);
}
