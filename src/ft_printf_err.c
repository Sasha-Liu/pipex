/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <hsliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:30:57 by hsliu             #+#    #+#             */
/*   Updated: 2023/01/04 15:31:00 by hsliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//display s1 + s2 on stderr
void	ft_printf_err(char *s1, char *s2)
{
	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
}
