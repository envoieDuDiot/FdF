/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:09:34 by gbryon            #+#    #+#             */
/*   Updated: 2018/01/24 15:39:40 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	mlx_stuff(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "FdF");
	p->img_ptr = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->data = (int *) mlx_get_data_addr(p->img_ptr,
			&p->bpp, &p->size_l, &p->endian);
	ft_drawer(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img_ptr, 0, 0);
	mlx_loop(p->mlx);
}
