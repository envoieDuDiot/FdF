/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/02/13 08:52:09 by gbryon           ###   ########.fr       */
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
//	p->wh = 1200;
//	p->ht = 800;
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
	if (k == UP)
	{
		
	}
	if (k == DOWN)
		printf("DOWN\n");
	if (k == LEFT)
		printf("LEFT\n");
	if (k == RIGHT)
		printf("RIGHT\n");
	if (k == ZERO)
		printf("0\n");

	if (k == ONE)
		printf("1\n");

	if (k == TWO)
		printf("2\n");

	if (k == THREE)
		printf("3\n");

	if (k == FOUR)
		printf("4\n");

	if (k == FIVE)
		printf("5\n");

	if (k == SIX)
		printf("6\n");

	if (k == SEVEN)
		printf("7\n");

	if (k == EIGHT)
		printf("8\n");

	if (k == NINE)
		printf("9\n");

	if (k == PLUS)
		printf("+\n");

	if (k == MINUS)
		printf("-\n");

	if (k == MULT)
		printf("*\n");

	if (k == DIV)
		printf("/\n");

	return (0);
}
