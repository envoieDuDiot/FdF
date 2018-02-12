/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:18:28 by gbryon            #+#    #+#             */
/*   Updated: 2018/02/08 16:56:40 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		check_file(t_param *p)
{
	char	*line;
	int		ret;

	line = NULL;
	p->nb_chars = 0;
	p->nb_lines = 0;
	while ((ret = get_next_line(p->fd, &line)) > 0)
	{
		if (p->nb_chars == 0)
			p->nb_chars = count_chars(line);
		else
		{
			if (count_chars(line) != p->nb_chars)
			{
				return (-1);
			}
		}
		p->nb_lines++;
	}
/*	printf("chars = %d\n", p->nb_chars);
	printf("lines = %d\n", p->nb_lines);
	printf("ttl = %d\n", p->total_chars);*/
	p->total_chars = (p->nb_chars) * (p->nb_lines);
//	printf("ttl = %d\n", p->total_chars);
	if (!(p->pt = malloc(sizeof(t_pt) * (p->total_chars + 1))))
	{
		return (-1);
	}
	return (0);
	
}

int		fill_t_pt(t_param *p)
{
	char	*line;
	int		ret;
	char	**tab;
	int		x;
	int		y;
	int		i;

	line = NULL;
	i = 0;
	y = 0;
	while ((ret = get_next_line(p->fd, &line)) > 0)
	{
		x = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[x] != NULL)
		{
			p->pt[i].x = x;
			p->pt[i].y = y;
			p->pt[i].z = ft_atoi(tab[x]);
	///		printf("  tab[%d] = %s // ", x, tab[x]);
			free(tab[x]);
	//		printf("z : %f", p->pt[i].z);
			printf("i= %d /x= %f /y= %f /z= %f\n", i, p->pt[i].x, p->pt[i].y, p->pt[i].z);
			i++;
			x++;
		}
	printf("ttl = %d\n", p->total_chars);
	//	printf("i = %d, ttl = %d", i, p->total_chars);
		free(tab);
		y++;
	}
	return (0);
}

int		parsing(t_param *p)
{
	if (check_file(p) == -1)
		return (-1);
	close(p->fd);
	p->fd = open(p->argv, O_RDONLY);
	if (fill_t_pt(p) == -1)
	{
		return (-1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_param		p;

	if (ac == 2)
	{
		initial(&p);
		p.argv = av[1];
		p.fd = open(p.argv, O_RDONLY);
		if (parsing(&p) == (-1))
		{
			ft_putendl("parsing KO");
			return (0);
		}
		window_stuff(&p);
		mlx_stuff(&p);
		drawing(&p);
		mlx_key_hook(p.win, keycool, p.mlx);
		mlx_loop(p.mlx);
	}
	return (0);
}