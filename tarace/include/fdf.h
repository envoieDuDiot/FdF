/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:06:42 by gbryon            #+#    #+#             */
/*   Updated: 2018/01/30 14:14:05 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../libft/libft.h"
# include <math.h>
# include "mlx.h"
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ZOOM_IN 6
# define ZOOM_OUT 7
# define COLOR 8
# define WIDTH 2200
# define HEIGHT 1400

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
}				t_pt;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	char	*argv;

	int		previous_x;
	int		previous_y;
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		error;
	int		e2;

	int		**map;

	int		fd;
	int		nb_lines;
	int		nb_chars;
	t_pt	*pt;

	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_param;

void	launch(t_param *param);
int		alloc(t_param *param);
int		alloc_each_line(t_param *param);
int		alloc_lines(t_param *param);
int		count_chars(char *line);
void	info(void);
void	usage(void);

#endif
