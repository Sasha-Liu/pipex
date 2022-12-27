/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:33:59 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/27 14:34:29 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free_arg(t_cmd *cmd, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (cmd[i].arg[j])
		{
			free(cmd[i].arg[j]);
			j++;
		}
		free(cmd[i].arg);
		cmd[i].arg = NULL;
		i++;
	}
}

void	ft_free_pathname(t_cmd *cmd, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(cmd[i].pathname);
		cmd[i].pathname = NULL;
		i++;
	}
}

void	ft_free_cmd(t_cmd *cmd, int n)
{
	ft_free_pathname(cmd, n);
	ft_free_arg(cmd, n);
	free(cmd);
	cmd = NULL;
}
