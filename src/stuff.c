/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/02/15 17:05:40 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	mlx_stuff(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, p->wh, p->ht, "FdF");
	p->img = mlx_new_image(p->mlx, p->wh, p->ht);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->sz_ln, &p->endian);
}

void	window_stuff(t_param *p)
{
	p->wh = p->nb_chars * 60;
	p->ht = p->nb_lines * 55;
	p->tw = 64;
	p->th = 48;
	while (p->wh > 2200 || p->ht > 1200)
	{
		p->wh *= 0.8;
		p->ht *= 0.8;
	}
	while ((p->tw * p->nb_chars) > p->wh || (p->th * p->nb_lines) > p->ht)
	{
		p->tw /= 2.2;
		p->th /= 2.2;
	}
}

int		keycool(int k, t_param *p)
{
	int i;

	i = p->ht;
	if (k == ESC)
		exit(0);
//	if (k == DIV || k == MULT)
//		ft_DIV_MULT(p, k);
	return (0);
}
