/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 10:40:57 by gbryon            #+#    #+#             */
/*   Updated: 2018/01/24 15:39:26 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"



void	draw_the_fuck(int x, int y, t_param *p)
{
	p->dx = abs(x - p->previous_x);
	p->dy = abs(y - p->previous_y);
	p->sx = p->previous_x < x ? 1 : -1;
	p->sy = p->previous_y < y ? 1 : -1;
	p->error = (p->dx > p->dy ? p->dx : -(p->dy)) / 2;
	while (1)
	{
		mlx_pixel_put(p->mlx, p->win, p->previous_x, p->previous_y, 0xCC00FF);
		if (p->e2 > -(p->dx))
		{
			p->error -= p->dy;
			p->previous_x -= p->sx;
		}
		if (p->e2 < p->dy)
		{
			p->error += p->dx;
			p->previous_y += p->sy;
		}
	}
}

void	map_to_screen(int x, int y, t_param *p)
{
	p->x = (WIDTH / 5 * 2) + y + x;
	p->y = (HEIGHT / 5 * 2) + y - x - p->map[y][x];
	if (x == 0)
	{
		p->previous_y = p->y;
		p->previous_x = p->x;
	}
	draw_the_fuck(p->x, p->y, p);
	if (y > 0)
	{
		p->previous_x = (WIDTH / 5 * 2) + ( y - 1) + x;
		p->previous_y = (HEIGHT / 5 * 2) + (y - 1) - x - p->map[y][x];
		draw_the_fuck(p->x, p->y, p);
	}
	p->previous_y = y;
	p->previous_x = x;
	
}

void	ft_drawer(t_param *p)
{
	int		x;
	int		y;

	y = 0;
	while (y < p->nb_lines)
	{
		x = 0;
		while (x < p->nb_chars)
		{
			map_to_screen(x, y, p);
			x++;
		}
		y++;
	}
}
