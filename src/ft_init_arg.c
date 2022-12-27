/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:03:07 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/26 14:07:29 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//ex : ./pipex infile "ls -l" "wc -l" outfile
//argv[2] = "ls -l"
//cmd[1] = {"ls", "-l", NULL}
//
//argv[1] = "infile"
//cmd[0].argv = {"infile", NULL}
int	ft_init_arg(t_cmd *cmd, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc - 2)
	{
		cmd[i].arg = ft_split(argv[i + 1], ' ');
		if (cmd[i].arg == NULL)
		{
			while (i >= 1)
			{
				free(cmd[i].arg);
				i--;
			}
			return (-1);
		}
		i++;
	}
	return (1);
}
