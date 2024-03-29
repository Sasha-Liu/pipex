/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:17:08 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/09 11:26:06 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;

	if (argc < 5)
	{
		ft_printf("Usage: ./pipex infile cmd1 cmd2 outfile\n");
		return (0);
	}
	cmd = ft_init_cmd(argc, argv, envp);
	ft_fork(cmd, argc - 3);
	ft_free_cmd(cmd, argc - 3);
}
