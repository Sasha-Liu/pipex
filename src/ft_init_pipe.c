/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:43:24 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/27 17:16:29 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_arrange_pipe(t_cmd *cmd, int **p, int n);
static int	ft_open_pipe(int **p, int n);
static int	**ft_malloc_pipe(int n);
static void	ft_free_pipe(int **p, int n);

int	ft_init_pipe(t_cmd *cmd, int n)
{
	int	**p;

	p = ft_malloc_pipe(n);
	if (p == NULL)
		return (-1);
	if (ft_open_pipe(p, n) == -1)
		return (ft_free_pipe(p, n), -1);
	if (ft_arrange_pipe(cmd, p, n) == -1)
		return (ft_free_pipe(p, n), -1);
	ft_free_pipe(p, n);
	return (1);
}

//n command
//(n - 1) * 2 pipe array
static int	ft_arrange_pipe(t_cmd *cmd, int **p, int n)
{
	int	i;
	int	valid;

	valid = 1;
	i = 1;
	cmd[0].write = dup(p[0][1]);
	close(p[0][1]);
	while (i < n - 1)
	{
		cmd[i].read = dup(p[i - 1][0]);
		cmd[i].write = dup(p[i][1]);
		close(p[i - 1][0]);
		close(p[i][1]);
		if (cmd[i].read == -1 || cmd[i].write == -1)
			valid = -1;
		i++;
	}
	cmd[n - 1].read = dup(p[n - 2][0]);
	close(p[n - 2][0]);
	if (cmd[0].write == -1 || cmd[n - 1].read == -1)
		valid = -1;
	return (valid);
}

//pipe array is (n - 1) * 2 
static int	ft_open_pipe(int **p, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (pipe(p[i]) == -1)
		{
			perror("Pipe");
			i--;
			while (i >= 0)
			{
				close(p[i][0]);
				close(p[i][1]);
				i--;
			}
			return (-1);
		}
		i++;
	}
	return (1);
}

//malloc a (n - 1) * 2 array
static int	**ft_malloc_pipe(int n)
{
	int	i;
	int	**p;

	p = malloc(sizeof(int *) * (n - 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < n - 1)
	{
		p[i] = malloc(sizeof(int) * 2);
		if (p[i] == NULL)
		{
			while (i >= 0)
			{
				free(p[i]);
				i--;
			}
			return (free(p), NULL);
		}
		i++;
	}
	return (p);
}

//free (n - 1) * 2 pipe array
static void	ft_free_pipe(int **p, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		free(p[i]);
		i++;
	}
	free(p);
}
