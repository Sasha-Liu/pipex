/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:38:27 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/27 17:06:05 by hsliu            ###   ########.fr       */
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
	int		read;
	int		write;
}t_cmd;

int	ft_init_arg(t_cmd *cmd, int n, char **argv);
int	ft_init_pathname(t_cmd *cmd, int n, char **envp);
int	ft_init_pipe(t_cmd *cmd, int n);
t_cmd	*ft_init_cmd(int argc, char **argv, char **envp);
void	ft_free_arg(t_cmd *cmd, int n);
void	ft_free_pathname(t_cmd *cmd, int n);
void	ft_free_cmd(t_cmd *cmd, int n);
void	ft_middle_fork(t_cmd *cmd, int argc, char **argv);
void	ft_last_fork(t_cmd cmd, char *outfile);
void	ft_first_fork(t_cmd cmd, char *infile);

#endif
