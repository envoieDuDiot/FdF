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

void	mlx_stuff(t_param *p)
{
	p->win = mlx_new_window(p->mlx, p->wh, p->ht, "FdF");
	refresh(p);
	mlx_hook(p->win, 2, 0, keycool, p);
	mlx_loop(p->mlx);
}

void	init_bonus(t_param *p)
{
	p->on = 1;
	p->alt = 1;
	p->lr = 0;
	p->ud = 0;
	p->zoom = 0;
}
