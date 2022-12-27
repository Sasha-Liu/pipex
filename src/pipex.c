/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:17:08 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/27 15:24:46 by hsliu            ###   ########.fr       */
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
	
	int	i;
	i = 0;
	while (i < argc - 3)
	{
		ft_printf("cmd[ %d ] ", i);
		ft_printf(" pathname: %s\n", cmd[i].pathname);
		ft_printf("arg1: %s\targ2: %s\n", cmd[i].arg[0], cmd[i].arg[1]);
		i++;
	}


	ft_free_cmd(cmd, argc - 3);
}
