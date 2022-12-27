/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:17:13 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/26 14:22:02 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_init_cmd(int argc, char **argv, char **envp, t_cmd *cmd)
{
	cmd[argc - 1].pathname = NULL;
	if (ft_init_rdwr(argc, argv, cmd) == -1)
		return (0);
	if (ft_init_arg(cmd, argc, argv) == -1)
	{
		ft_free_rdwr(argc, cmd);
		return (0);
	}
	if (ft_init_pathname(cmd, argc, envp) == -1)
	{	
		ft_free_rdwr(argc, cmd);
		ft_free_arg(argc, cmd);
		return (0);
	}
	return (1);
}
