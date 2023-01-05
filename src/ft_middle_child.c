/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:29:11 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/05 15:41:10 by hsliu            ###   ########lyon.fr   */
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
	ft_printf_err("zsh: command not found: ", cmd[i].arg[0]);
	exit(EXIT_FAILURE);
}
