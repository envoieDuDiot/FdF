/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/02/13 10:02:03 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	mlx_stuff(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, p->wh, p->ht, "FdF");
	p->img = mlx_new_image(p->mlx, p->wh, p->ht);
}

void	window_stuff(t_param *p)
{
	p->wh = p->nb_chars * 42;
	p->ht = p->nb_lines * 28;
	p->tw = 48;
	p->th = 32;
	while (p->wh > 2200 || p->ht > 1200)
	{
		p->wh /= 1.1;
		p->ht /= 1.1;
	}
	while ((p->tw * p->nb_chars) > p->wh || (p->th * p->nb_lines) > p->ht)
	{
		p->tw /= 2;
		p->th /= 2;
	}
}

int		keycool(int k, t_param *p)
{
	int i;

	i = p->nb_chars;
	if (k == ESC)
		exit(0);
	return (0);
}
