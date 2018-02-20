/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/02/20 16:50:30 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		check_file(t_param *p)
{
	int		ret;

	p->line = NULL;
	p->nb_chars = 0;
	p->nb_lines = 0;
	while ((ret = get_next_line(p->fd, &(p->line))) > 0)
	{
		if (p->nb_chars == 0)
			p->nb_chars = count_chars(p->line);
		else
		{
			if (count_chars(p->line) != p->nb_chars)
				return (-1);
		}
		p->nb_lines++;
	}
	free(p->line);
	p->total_chars = (p->nb_chars) * (p->nb_lines);
	if (!(p->pt = malloc(sizeof(t_pt) * (p->total_chars + 1))))
		return (-1);
	return (0);
}

int		fill_t_pt(t_param *p)
{
	char	**tab;
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while ((p->ret = get_next_line(p->fd, &(p->line))) > 0)
	{
		x = 0;
		tab = ft_strsplit(p->line, ' ');
		while (tab[x] != NULL)
		{
			p->pt[i].x = x;
			p->pt[i].y = y;
			p->pt[i].z = ft_atoi(tab[x]);
			free(tab[x]);
			i++;
			x++;
		}
		free(tab);
		free(p->line);
		y++;
	}
	return (0);
}

int		parsing(t_param *p)
{
	p->fd = open(p->argv, O_RDONLY);
	if (check_file(p) == -1)
		return (-1);
	close(p->fd);
	p->fd = open(p->argv, O_RDONLY);
	if (fill_t_pt(p) == -1)
		return (-1);
	p->ptbfr = p->pt;
	return (0);
}

void	refresh(t_param *p)
{
	p->img = mlx_new_image(p->mlx, p->wh, p->ht);
	p->data = mlx_get_data_addr(p->img, &p->bpp, &p->sz_ln, &p->endian);
	drawing(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
}

void	mlx_stuff(t_param *p)
{
	p->win = mlx_new_window(p->mlx, p->wh, p->ht, "FdF");
	refresh(p);
	mlx_hook(p->win, 2, 0, keycool, p);
	mlx_loop(p->mlx);
}

void	init_bonus(t_param *p)
{
	p->on = 1;
	p->alt = 2;
	p->lr = 0;
	p->ud = 0;
	p->zoom = 0;
}

int		main(int ac, char **av)
{
	t_param		*p;

	if (!(p = malloc(sizeof(t_param))))
		return (EXIT_FAILURE);
	p->mlx = mlx_init();
	if (ac == 2)
	{
		initial(p);
		p->argv = av[1];
		if (parsing(p) == (-1))
		{
			ft_putendl("parsing KO");
			return (0);
		}
		window_stuff(p);
		init_bonus(p);
		mlx_stuff(p);
	}
	return (0);
}
