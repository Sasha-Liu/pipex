/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:22:30 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/27 14:24:22 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_error_free(t_cmd *cmd, int i);

//n is the number of cmd
//there are argc - 3 command 
//cmd[0] - cmd[ n - 1] are coomands
//cmd[n] is null
int	ft_init_arg(t_cmd *cmd, int n, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	while (i < n)
	{
		cmd[i].arg = ft_split(argv[j], ' ');
		if (cmd[i].arg == NULL)
		{
			ft_error_free(cmd, i);
			return (-1);
		}
		i++;
		j++;
	}
	cmd[i].arg = NULL;
	return (1);
}

static void	ft_error_free(t_cmd *cmd, int i)
{
	int	j;

	while (i >= 0)
	{
		j = 0;
		while (cmd[i].arg[j])
		{
			free(cmd[i].arg[j]);
			j++;
		}
		free(cmd[i].arg);
		i--;
	}
}
