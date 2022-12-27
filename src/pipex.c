/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:24:21 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/26 14:20:15 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	int		**pipefd;
	t_cmd	*cmd;

	if (argc < 5)
	{
		ft_printf("Usage : infile cmd1 cmd2 outfile\n");
		return (0);
	}
	cmd = malloc(sizeof(t_cmd) * (argc));
	if (cmd == NULL)
		return (free(cmd), 0);
	if (ft_init_cmd(argc, argv, envp, cmd) == 0)
		return (0);
	pipefd = ft_init_pipe(argc, cmd);
	if (pipefd == NULL)
		return (ft_free_cmd(argc, cmd, pipefd), 0);
	ft_fork(argc, cmd);
	ft_free_cmd(argc, cmd, pipefd);
}
