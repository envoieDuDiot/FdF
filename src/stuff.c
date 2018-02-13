/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/02/13 15:42:49 by gbryon           ###   ########.fr       */
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

/*void	ft_DIV_MULT(t_param *p, int k)
{
	if (k == DIV)
	{
		p->zoom -= 1;
		mlx_clear_window(p->mlx, p->win);
		drawing(p);
	}
	if (k == MULT)
	{
		p->zoom += 1;
		mlx_clear_window(p->mlx, p->win);
		mlx_destroy_image(p->mlx, p->img);
		drawing(p);
	}
}
*/
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
