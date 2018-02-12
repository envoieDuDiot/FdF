#include "../include/fdf.h"

void	initial(t_param *p)
{
	p->dx = 0;
	p->dy = 0;
	p->sx = 0;
	p->sy = 0;
	p->error = 0;
	p->e2 = 0;
	p->nb_lines = 0;
	p->nb_chars = 0;
	p->total_chars = 0;
	p-> wh = 0;
	p->ht = 0;
	p->tw = 0;
	p->th = 0;
	p->fd = 0;
}
