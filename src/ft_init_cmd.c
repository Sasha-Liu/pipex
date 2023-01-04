/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:25:13 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/04 13:41:15 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_cmd	*ft_init_cmd(int argc, char **argv, char **envp)
{
	int		n;
	t_cmd	*cmd;

	n = argc - 3;
	cmd = malloc(sizeof(t_cmd) * (n + 1));
	if (cmd == NULL)
		return (NULL);
	if (ft_init_pipe(cmd, n) == -1)
		return (free(cmd), NULL);
	if (ft_init_arg(cmd, n, argv) == -1)
		return (free(cmd), NULL);
	if (ft_init_pathname(cmd, n, envp) == -1)
		return (ft_free_arg(cmd, n), free(cmd), NULL);
	if (ft_init_file(cmd, argc, argv) == -1)
	{
		ft_free_arg(cmd, n);
		ft_free_pathname(cmd, n);
		free(cmd);
		return (NULL);
	}
	return (cmd);
}

int	ft_init_file(t_cmd *cmd, int argc, char **argv)
{
	cmd[0].file = ft_strdup(argv[1]);
	cmd[argc - 4].file = ft_strdup(argv[argc - 1]);
	if (cmd[0].file == NULL || cmd[argc - 4].file == NULL)
	{
		free(cmd[0].file);
		free(cmd[argc - 4].file);
		return (-1);
	}
	return (1);
}
