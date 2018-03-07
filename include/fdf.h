/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbryon <gbryon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:45:19 by gbryon            #+#    #+#             */
/*   Updated: 2018/03/07 11:31:47 by gbryon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"

# define ESC	53
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define ZERO	82
# define PLUS	69
# define MINUS	78
# define MULT	67
# define DIV	75

typedef struct	s_pt
{
	double		x;
	double		y;
	double		z;
}				t_pt;

typedef struct	s_param
{
	void		*mlx;
	void		*win;

	void		*img;
	int			bpp;
	int			endian;
	int			sz_ln;
	char		*data;

	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			error;
	int			e2;

	double		on;
	double		alt;
	double		ud;
	double		lr;
	double		zoom;
	double		r;
	double		g;
	double		b;

	int			nb_lines;
	int			nb_chars;
	int			total_chars;

	int			wh;
	int			ht;
	int			tw;
	int			th;

	t_pt		*pt;
	t_pt		*ptbfr;

	char		*argv;
	int			fd;
	int			ret;
	char		*line;

}				t_param;

int				count_chars(char *line);
void			init_bonus(t_param *p);
void			mlx_stuff(t_param *p);
void			refresh(t_param *p);
int				parsing(t_param *p);
int				fill_t_pt(t_param *p);
int				check_file(t_param *p);
void			drawing(t_param *p);
void			tracer(t_param *p, t_pt p1, t_pt p2);
void			fill_pix(t_param *p, int x, int y);
void			iso_to_screen(t_param *p);
void			keycool2(int k, t_param *p);
int				keycool(int k, t_param *p);
void			window_stuff(t_param *p);
void			zoom_fdf(int k, t_param *p);
void			alt_fdf(t_param *p);
void			move_fdf(t_param *p);
void			initial(t_param *p);
void			check_ext(t_param *p);
void			mouse_hook(int k, int x, int y, t_param *p);

#endif
