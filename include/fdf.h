/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:45:19 by gbryon            #+#    #+#             */
/*   Updated: 2018/02/08 18:23:31 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"


# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ZERO 82
# define ONE 83
# define TWO 84
# define THREE 85
# define FOUR 86
# define FIVE 87
# define SIX 88
# define SEVEN 89
# define EIGHT 91
# define NINE 92
# define PLUS 69
# define MINUS 78
# define MULT 67
# define DIV 75

typedef struct s_pt
{
	float		x;
	float		y;
	float		z;
}				t_pt;

typedef struct s_param
{
	void	*mlx;
	void	*win;

	void	*img;
	int		bpp;
	int		endian;
	int		sz_ln;
	char	*data;

	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		error;
	int		e2;

	int		nb_lines;
	int		nb_chars;
	int		total_chars;

	int		wh;
	int		ht;
	int		tw;
	int		th;

	t_pt	*pt;

	char	*argv;
	int		fd;

}			t_param;

t_pt	*iso_to_screen(t_param *param);
void	fill_pix(t_param *param, int x, int y);
void	tracer(t_param *param, t_pt p1, t_pt p2);
void	drawing(t_param *p);
void	mlx_stuff(t_param *p);
void	window_stuff(t_param *p);
int		keycool(int keycode, t_param *p);
int		count_chars(char *line);
void	initial(t_param *p);

#endif
