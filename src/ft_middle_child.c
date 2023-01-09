/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:29:11 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/09 11:52:59 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_middle_child(t_cmd *cmd, int i)
{
	if (dup2(cmd[i].read, 0) == -1)
	{
		perror("in middle child : dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(cmd[i].write, 1) == -1)
	{
		perror("in middle child : dup2");
		exit(EXIT_FAILURE);
	}
	execve(cmd[i].pathname, cmd[i].arg, NULL);
	if (ft_strncmp(cmd[0].arg[0], "", 1) == 0)
		write(2, "zsh: permission denied:\n", 25);
	else
		ft_printf_err("zsh: command not found:", cmd[0].arg[0]);
	exit(EXIT_FAILURE);
}
