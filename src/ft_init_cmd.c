/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:25:13 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/27 15:15:14 by hsliu            ###   ########.fr       */
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
	return (cmd);
}
