/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:10:48 by gbryon            #+#    #+#             */
/*   Updated: 2018/01/18 13:10:50 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	usage(void)
{
	ft_putstr("usage: ./fdf [-info]\n      ./fdf map.fdf\n");
}

void	info(void)
{
	ft_putstr("how to use the fdf:\n- ESC: quit the programm\n- Z: zoom in\n");
	ft_putstr("- X: zoom out\n- C: change color\n- arrows: deplace map\n");
}

int		count_chars(char *line)
{
	int		nb_chars;

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
