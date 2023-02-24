/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:43:24 by hsliu             #+#    #+#             */
/*   Updated: 2023/02/24 10:20:20 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_arrange_pipe(t_cmd *cmd, int *p, int n);
static int	ft_open_pipe(int *p, int n);
static int	*ft_malloc_pipe(int n);
static void	ft_free_pipe(int *p);

int	ft_init_pipe(t_cmd *cmd, int n)
{
	int	*p;

	p = ft_malloc_pipe(n);
	if (p == NULL)
		return (-1);
	if (ft_open_pipe(p, n) == -1)
		return (ft_free_pipe(p), -1);
	if (ft_arrange_pipe(cmd, p, n) == -1)
		return (ft_free_pipe(p), -1);
	ft_free_pipe(p);
	return (1);
}

//n command
//(n - 1) * 2 pipe array
static int	ft_arrange_pipe(t_cmd *cmd, int *p, int n)
{
	int	i;

	cmd[0].write = dup(p[1]);
	close(p[1]);
	i = 1;
	while (i < n - 1)
	{
		cmd[i].read = dup(p[2 * (i - 1)]);
		cmd[i].write = dup(p[i * 2 + 1]);
		close(p[2 * (i - 1)]);
		close(p[i * 2 + 1]);
		i++;
	}
	cmd[n - 1].read = dup(p[2 * n - 4]);
	close(p[2 * n - 4]);
	return (0);
}

//pipe array is (n - 1) * 2 
static int	ft_open_pipe(int *p, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (pipe(p + i) == -1)
		{
			perror("Pipe");
			return (-1);
		}
		i = i + 2;
	}
	return (1);
}

//malloc a (n - 1) * 2 array
static int	*ft_malloc_pipe(int n)
{
	int	*p;

	p = malloc(sizeof(int) * (2 * n - 2));
	if (p == NULL)
		return (NULL);
	return (p);
}

//free (n - 1) * 2 pipe array
static void	ft_free_pipe(int *p)
{
	free(p);
}
