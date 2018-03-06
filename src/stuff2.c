/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:06:56 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/02 18:06:59 by gbryon           ###   ########.fr       */
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
		i++;
	}
	refresh(p);
}

void	alt_fdf(t_param *p)
{
	int		i;

	i = 0;
	while (i < p->total_chars)
	{
		if (p->pt[i].z > 0)
		{
			p->pt[i].y -= p->alt;
		}
		i++;
	}
}

void	zoom_fdf(int k, t_param *p)
{
	int		i;

	i = 0;
	while (i <= p->total_chars)
	{
		p->pt[i].x *= p->zoom;
		p->pt[i].y *= p->zoom;
		if (k == MINUS)
		{
			p->pt[i].x += 100;
			p->pt[i].y += 100;
		}
		if (k == PLUS)
		{
			p->pt[i].x -= 100;
			p->pt[i].y -= 100;
		}
		i++;
	}
	refresh(p);
}
