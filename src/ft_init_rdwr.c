/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rdwr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:44:12 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/26 14:48:47 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_init_rdwr(int argc, char	**argv, t_cmd *cmd)
{
	char	*arg1;
	char	*arg2;

	cmd[0].pathname = ft_strdup("./reader");
	cmd[argc - 2].pathname = ft_strdup("./writer");
	if (cmd[0].pathname == NULL || cmd[argc - 2].pathname == NULL)
		return (free(cmd[0].pathname), free(cmd[argc - 2].pathname), -1);
	arg1 = ft_strjoin("./reader ", argv[1]);
	arg2 = ft_strjoin("./writer ", argv[argc - 1]);
	if (arg1 == NULL || arg2 == NULL)
		return (free(arg1), free(arg2), -1);
	cmd[0].arg = ft_split(arg1, ' ');
	cmd[argc - 2].arg = ft_split(arg2, ' ');
	if (cmd[0].arg == NULL || cmd[argc - 2].arg == NULL)
	{
		free(cmd[0].pathname);
		free(cmd[argc - 2].pathname);
		free(cmd[0].arg);
		free(cmd[argc - 2].arg);
		return (free(arg1), free(arg2), -1);
	}
	free(arg1);
	free(arg2);
	return (1);
}
