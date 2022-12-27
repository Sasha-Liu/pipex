/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:38:27 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/26 14:49:29 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libftprintf/ft_printf.h"
# include "../libftprintf/libft/libft.h"

typedef struct s_cmd{
	char	*pathname;
	char	**arg;
	int		*read_pipe;
	int		*write_pipe;
}t_cmd;

int		ft_init_pathname(t_cmd *cmd, int argc, char **envp);
int		ft_init_arg(t_cmd *cmd, int argc, char **argv);
int		ft_init_rdwr(int argc, char **argv, t_cmd *cmd);
int		**ft_init_pipe(int argc, t_cmd *cmd);
void	ft_free_pipe(int **pipefd, int argc);
int		ft_init_cmd(int argc, char **argv, char **envp, t_cmd *cmd);
void	ft_fork(int argc, t_cmd *cmd);
void	ft_free_rdwr(int argc, t_cmd *cmd);
void	ft_free_arg(int argc, t_cmd *cmd);
void	ft_free_pathname(int argc, t_cmd *cmd);
void	ft_free_pipe(int **pipefd, int argc);
void	ft_free_cmd(int argc, t_cmd *cmd, int **pipefd);

#endif
