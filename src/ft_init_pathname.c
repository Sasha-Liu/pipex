/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pathname.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:33:42 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/04 14:38:37 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*ft_access(char **path, char *name);
static char	**ft_cp_path(char **envp);
static char	**ft_add_slash(char **path);
static void	ft_free_path(char **path);

//it must be called after ft_init_arg
//n is the number of command
//cmd[0] -  cmd[n - 1] 
//cmd[n] = NULL
int	ft_init_pathname(t_cmd *cmd, int n, char **envp)
{
	int		i;
	char	**path;

	path = ft_cp_path(envp);
	path = ft_add_slash(path);
	if (path == NULL)
		return (-1);
	i = 0;
	while (i < n)
	{
		cmd[i].pathname = ft_access(path, cmd[i].arg[0]);
		if (cmd[i].pathname == NULL)
		{
			while (i >= 0)
			{
				free(cmd[i].pathname);
				i--;
			}
			return (-1);
		}
		i++;
	}
	cmd[n].pathname = NULL;
	ft_free_path(path);
	return (1);
}

static void	ft_free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

//use ft_strjoin to combine path and name
//use access function to verify if it's executable
//return the pathname when finding the right path
//return NULL when malloc failed, or when command doesn't exist
//if command doesn't exist, errno will be set by access
//use perror to print error message
static char	*ft_access(char **path, char *name)
{
	int		i;
	char	*pathname;

	i = 0;
	while (path[i])
	{
		pathname = ft_strjoin(path[i], name);
		if (pathname == NULL)
			return (NULL);
		if (access(pathname, X_OK) == 0)
			return (pathname);
		else
			free(pathname);
		i++;
	}
	pathname = ft_strjoin("", name);
	if (pathname == NULL)
		return (NULL);
	return (pathname);
}

//read envp, use ft_split to copy the line about path
static char	**ft_cp_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			break ;
		i++;
	}
	if (envp[i] == NULL)
		return (NULL);
	path = ft_split(envp[i] + 5, ':');
	return (path);
}

//add slash to path with strjoin
//if malloc failed, free every string in path
static char	**ft_add_slash(char **path)
{
	int		i;
	char	*new;

	i = 0;
	while (path[i])
	{
		new = ft_strjoin(path[i], "/");
		if (new == NULL)
		{
			i = 0;
			while (path[i])
			{
				free(path[i]);
				i++;
			}
			return (NULL);
		}
		free (path[i]);
		path[i] = new;
		i++;
	}
	return (path);
}
