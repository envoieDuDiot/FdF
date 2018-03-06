/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/02/28 12:22:42 by gbryon           ###   ########.fr       */
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
		if (!(p->line) || p->line[0] == '\0')
			exit(0);
		if (p->nb_chars == 0)
			p->nb_chars = count_chars(p->line);
		else
		{
			if (count_chars(p->line) != p->nb_chars)
				return (-1);
		}
		p->nb_lines++;
		free(p->line);
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
	if ((p->fd = open(p->argv, O_RDONLY)) == -1)
	{
		ft_putendl("wrong file\nenter a map.fdf");
		return (-1);
	}
	if (check_file(p) == -1)
		return (-1);
	close(p->fd);
	p->fd = open(p->argv, O_RDONLY);
	if (fill_t_pt(p) == -1)
		return (-1);
	free(p->line);
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

void check_ext(t_param *p)
{
	int i;

	i = 0;
	while (p->argv[i])
	{
		if (p->argv[i] == '.' && p->argv[i + 1] == 'f')
		{
			if (p->argv[i + 2] == 'd' && p->argv[i + 3] == 'f')
				break ;
			else
			{
				ft_putendl("wrong file\nenter a map.fdf");
				exit(0);
			}
		}
		i++;
	}
}

void check_ac(int ac)
{
	if (ac < 2 || ac > 2)
	{
		ft_putendl("enter a map.fdf");
		exit (0);
	}
}

int		main(int ac, char **av)
{
	t_param		*p;

	if (!(p = malloc(sizeof(t_param)))
	|| !(p->mlx = mlx_init()))
		return (EXIT_FAILURE);
	p->pt = NULL;
	check_ac(ac);
	if (ac == 2)
	{
		initial(p);
		p->argv = av[1];
		check_ext(p);
		if (parsing(p) == (-1))
			return (0);
		window_stuff(p);
		init_bonus(p);
		mlx_stuff(p);
	}
	return (0);
}
