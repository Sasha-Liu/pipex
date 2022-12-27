/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:57:02 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/26 15:01:45 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//first check if file exists
//read to std output
int	main(int argc, char **argv)
{
	char	*path_to_file;
	int		fd;
	char	c;

	if (argc != 2)
		exit(EXIT_FAILURE);
	path_to_file = argv[1];
	if (access(path_to_file, R_OK) != 0)
	{
		write(2, "No such file or directory: ", 27);
		write(2, path_to_file, ft_strlen(path_to_file));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	fd = open(path_to_file, O_RDONLY);
	while (read(fd, &c, 1) == 1)
	{
		if (write(1, &c, 1) != 1)
		{
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}
