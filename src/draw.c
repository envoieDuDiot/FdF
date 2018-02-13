/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/02/13 08:51:12 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_pt	*iso_to_screen(t_param *p)
{
	int		i;
	int		isoX;
	int		isoY;
	i = 0;
	while (i < p->total_chars)
	{
		p->pt[i].x = (p->pt[i].x * p->tw) / 2;
		p->pt[i].y = p->pt[i].y * p->th;
		isoX = p->pt[i].x - p->pt[i].y;
		isoY = ((p->pt[i].x + p->pt[i].y) / 2) - (p->pt[i].z * 1.3);
		p->pt[i].x = isoX + p->wh / 2;
		p->pt[i].y = (isoY + p->ht / 4);
		i++;
	}
	return (p->pt);
}

void		fill_pix(t_param *p, int x, int y)
{
	p->data[(y * (p->sz_ln)) + (4 * x)] = 0xFF;
	p->data[(y * (p->sz_ln)) + (4 * x) + 1] = 0xFF;
	p->data[(y * (p->sz_ln)) + (4 * x) + 2] = 0xFF;
}

void		tracer(t_param *p, t_pt p1, t_pt p2)
{
	int		x;
	int		y;
	int		dx;
	int		dy;

	y = 0;
	x = p1.x;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
//	printf("x.%d.pt1.x.%f.pt2.x.%f.pt1.y.%f.pt2.y.%f.dx.%d.dy.%d..", x, p1.x, p2.x, p1.y, p2.y, dx, dy);
	while (x < p2.x)
	{
		y = p1.y + dy * (x - p1.x) / dx;
		fill_pix(p, x, y);
		x++;
	}
}

void	drawing(t_param *p)
{
	int		i;

	i = 0;
	p->pt = iso_to_screen(p);
	p->data = ft_strnew(p->wh * p->ht * 4);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->sz_ln, &p->endian);
	while (i < p->total_chars)
	{
		if (p->pt[i + 1].x && i < p->total_chars)
			tracer(p, p->pt[i], p->pt[i + 1]);
		if (i + p->nb_chars < p->total_chars )
			tracer(p, p->pt[i + p->nb_chars], p->pt[i]);
		i++;
		//		printf("i = %d -- ", i);
		//		printf("p->total_chars = %d\n", p->total_chars);
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
