/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:11:12 by gbryon            #+#    #+#             */
/*   Updated: 2018/01/30 14:25:59 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		alloc_lines(t_param *p)
{
	char	*line;
	int		ret;

	line = NULL;
	p->nb_chars = 0;
	p->nb_lines = 0;
	while ((ret = get_next_line(p->fd, &line)) > 0)
	{
		if (p->nb_chars == 0)
		{
			p->nb_chars = count_chars(line);
			printf("%d\n", p->nb_chars);
		}
		else
		{
			if (count_chars(line) != p->nb_chars)
			{
			printf("%d", p->nb_chars);
			printf("domage");
				return (-1);
			}
		}
		p->nb_lines++;
	}
	p->map = (int **)ft_memalloc(sizeof(int *) * p->nb_lines);
	return (0);
}

int		alloc_each_line(t_param *p)
{
	char	*line;
	char	**tab;
	int		ret;
	int x;
	int y;

	line = NULL;
	y = 0;
	while ((ret = get_next_line(p->fd, &line)) > 0)
	{
		x = 0;
		tab = ft_strsplit(line, ' ');
		p->map[y] = (int *)ft_memalloc(sizeof(int) * p->nb_chars);
		while (tab[x] != NULL)
		{
			p->map[y][x] = ft_atoi(tab[x]);
			free(tab[x]);
			x++;
		}
		free(tab);
		y++;
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int		treat(t_param *p)
{
	if (alloc_lines(p) == -1)
		return (-1);
	close(p->fd);
	p->fd = open(p->argv, O_RDONLY);
//	if (alloc_each_line(p) == -1)
//	{
//		return (-1);
//	}
	return (0);
}

t_pt	*map_to_struc(t_param *p)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (y < p->nb_lines)
	{
		x = 0;
		while (x < p->nb_chars)
		{
			p->pt[i].x = x;
			p->pt[i].y = y;
			p->pt[i].z = p->map[y][x];
			printf("%d.", p->pt[i].x);
			printf("%d.", p->pt[i].y);
			printf("%d   ", p->pt[i].z);
			x++;
			i++;
		}
		y++;
	}
	return (p->pt);
}

void	launch(t_param *p)
{
	int i = 0;
	int j = 0;
	if (treat(p) == -1)
	{
		ft_putstr("The programm can't be launched");
		return ;
	}
	p->pt = map_to_struc(p);
//	mlx_stuff(p);
}

int		main(int ac, char **av)
{
	t_param		p;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "-info") == 0)
		{
			info();
			return(0);
		}
		p.argv = av[1];
		p.fd = open(p.argv, O_RDONLY);
		launch(&p);
	}
	else
		usage();
	return(0);
}
