/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/02/20 15:28:07 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		count_chars(char *line)
{
	int			nb_chars;

	nb_chars = 0;
	while (*line && *line == ' ')
		line++;
	while (*line)
	{
		while (*line && *line != ' ')
			line++;
		nb_chars++;
		while (*line && *line == ' ')
			line++;
	}
	return (nb_chars);
}
