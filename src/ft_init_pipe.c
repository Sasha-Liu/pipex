/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:46:07 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/26 14:20:35 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	**ft_malloc_pipe(int argc);
static void	ft_arrange_pipe(int **pipefd, int argc, t_cmd *cmd);
static int	ft_open_pipe(int argc, int **pipefd);

int	**ft_init_pipe(int argc, t_cmd *cmd)
{
	int	**pipefd;
	int	res;

	pipefd = ft_malloc_pipe(argc);
	res = ft_open_pipe(argc, pipefd);
	if (res == -1)
	{
		ft_free_pipe(pipefd, argc);
		return (NULL);
	}
	ft_arrange_pipe(pipefd, argc, cmd);
	return (pipefd);
}

//we have (argc - 2) pipe
//and (argc - 1) struct 
//cmd[0].read_pipe will be define later
//so is cmd[argc - 2].write_pipe
static void	ft_arrange_pipe(int **pipefd, int argc, t_cmd *cmd)
{
	int	i;

	cmd[0].write_pipe = &(pipefd[0][1]);
	i = 1;
	while (i <= argc - 3)
	{
		cmd[i].read_pipe = &(pipefd[i - 1][0]);
		cmd[i].write_pipe = &(pipefd[i][1]);
		i++;
	}
	cmd[argc - 2].read_pipe = &(pipefd[argc - 3][0]);
}

//if argc = 5, then we need argc - 2 = 3 pipe
static int	ft_open_pipe(int argc, int **pipefd)
{
	int	i;

	i = 0;
	while (i < argc - 2)
	{
		if (pipe(pipefd[i]) == -1)
		{
			perror("Pipe");
			return (-1);
		}
		i++;
	}
	return (1);
}

static int	**ft_malloc_pipe(int argc)
{
	int	**pipefd;
	int	i;

	pipefd = malloc(sizeof(int *) * (argc - 2));
	if (pipefd == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 2)
	{
		pipefd[i] = malloc(sizeof(int) * 2);
		if (pipefd[i] == NULL)
		{
			while (i >= 0)
			{
				free(pipefd[i]);
				i--;
			}
			return (free(pipefd), NULL);
		}
		i++;
	}
	return (pipefd);
}
