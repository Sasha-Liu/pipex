/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:17:08 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/27 17:05:51 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;

	if (argc < 5)
	{
		ft_printf("Usage: ./pipex infile cmd1 cmd2 outfile\n");
		return (0);
	}
	cmd = ft_init_cmd(argc, argv, envp);
	ft_first_fork(cmd[0], argv[1]);
	ft_middle_fork(cmd, argc, argv);
	ft_last_fork(cmd[argc - 4], argv[argc - 1]);
	ft_free_cmd(cmd, argc - 3);
}


