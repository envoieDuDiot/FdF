/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/02/20 16:54:10 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	move_fdf(t_param *p)
{
	int		i;

	i = 0;
	while (i <= p->total_chars)
	{
		p->pt[i].x += p->lr;
		p->pt[i].y += p->ud;
		if (p->pt[i].z != 0)
			p->pt[i].z -= p->alt;
		i++;
	}
	refresh(p);
}

void	zoom_fdf(t_param *p)
{
	int		i;

	i = 0;
	while (i <= p->total_chars)
	{
		p->pt[i].x *= p->zoom;
		p->pt[i].y *= p->zoom;
		i++;
	}
	refresh(p);
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
	int		i;

	i = p->ht;
	p->on = 0;
	p->alt = 1;
	p->lr = 0;
	p->ud = 0;
	if (k == ESC)
		exit(0);
	if (k == ZERO)
	{
		free(p->pt);
		parsing(p);
		init_bonus(p);
		p->pt = p->ptbfr;
		refresh(p);
	}
	if (k == UP || k == DOWN || k == LEFT || k == RIGHT || k == DIV || k == MULT)
	{
		if (k == UP)
			p->ud -= 10;
		if (k == DOWN)
			p->ud += 10;
		if (k == LEFT)
			p->lr -= 10;
		if (k == RIGHT)
			p->lr += 10;
		if (k == MULT)
			p->alt *= 0.8;
		if (k == DIV)
			p->alt *= -0.8;
		move_fdf(p);
	}
	if (k == PLUS || k == MINUS)
	{
		p->zoom = 1;
		if (k == PLUS)
			p->zoom += 0.1;
		if (k == MINUS)
			p->zoom -= 0.1;
		zoom_fdf(p);
	}
	return (0);
}
