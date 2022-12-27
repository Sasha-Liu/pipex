/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:30:04 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/26 16:41:17 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

//check acces to file
//write from stdin to file
//if the file does not exit, create it
int	main(int argc, char **argv)
{
	char	*path_to_file;
	int		fd;
	char	c;

	if (argc != 2)
		exit(EXIT_FAILURE);
	path_to_file = argv[1];
	fd = open(path_to_file, O_CREAT | O_WRONLY, 0644);
	if (fd <= 0)
		printf("fd value : %d", fd);
	while (read(0, &c, 1) == 1)
	{
		if (write(fd, &c, 1) != 1)
		{
			perror("writer program");
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}
