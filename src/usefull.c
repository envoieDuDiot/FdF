/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/07 11:41:04 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		count_chars(char *line)
{
	int			nb_chars;

	nb_chars = 0;
	while (*line && *line == ' ')
		line++;
	while (*line)
	{
		while (*line && *line != ' ')
			line++;
		nb_chars++;
		while (*line && *line == ' ')
			line++;
	}
	return (nb_chars);
}

void	mlx_stuff(t_param *p)
{
	if (!(p->mlx = mlx_init()))
		exit(EXIT_FAILURE);
	p->win = mlx_new_window(p->mlx, p->wh, p->ht, "FdF");
	refresh(p);
	mlx_hook(p->win, 2, 0, keycool, p);
	mlx_loop(p->mlx);
}

void	init_bonus(t_param *p)
{
	p->on = 1;
	p->alt = 1;
	p->lr = 0;
	p->ud = 0;
	p->zoom = 0;
}

void	refresh(t_param *p)
{
	p->img = mlx_new_image(p->mlx, p->wh, p->ht);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->sz_ln, &p->endian);
	drawing(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
}

void	check_ext(t_param *p)
{
	if (p->argv[ft_strlen(p->argv) - 4] != '.'
	&& p->argv[ft_strlen(p->argv) - 3] != 'f')
	{
		ft_putendl("wrong ext file mother fucker");
		exit(EXIT_FAILURE);
	}
}
