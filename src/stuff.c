/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/07 11:41:17 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	window_stuff(t_param *p)
{
	p->wh = p->nb_chars * 60;
	p->ht = p->nb_lines * 55;
	p->tw = 96;
	p->th = 48;
	while (p->wh > 1920 || p->ht > 1080)
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

void	ft_esc(int k, t_param *p)
{
	if (k == ESC)
	{
		p->on = 0;
		exit(0);
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
	ft_esc(k, p);
	if (k == ZERO)
	{
		parsing(p);
		init_bonus(p);
		p->pt = p->ptbfr;
		refresh(p);
	}
	if (k == DIV || k == MULT)
	{
		if (k == MULT)
			p->alt *= 0.8;
		if (k == DIV)
			p->alt *= -0.8;
		alt_fdf(p);
	}
	keycool2(k, p);
	return (0);
}

void	keycool2(int k, t_param *p)
{
	if (k == UP || k == DOWN || k == LEFT
			|| k == RIGHT || k == DIV || k == MULT)
	{
		if (k == UP)
			p->ud -= 25;
		if (k == DOWN)
			p->ud += 25;
		if (k == LEFT)
			p->lr -= 25;
		if (k == RIGHT)
			p->lr += 25;
		move_fdf(p);
	}
	if (k == PLUS || k == MINUS)
	{
		p->zoom = 1;
		if (k == PLUS)
			p->zoom += 0.2;
		if (k == MINUS)
			p->zoom -= 0.2;
		zoom_fdf(k, p);
	}
}
