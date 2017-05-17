#include "../inc/ft_printf.h"

void	init_flags(*p)
{
	t_flags	f;

	while (is_conv(*p->fmt) == 0)
	{
		f.hash = *p->fmt == '#' ? 1 : 0;
		f.zero = *p->fmt == '0' ? 1 : 0;
		f.neg = *p->fmt == '-' ? 1 : 0;
		f.pos = *p->fmt == '+' ? 1 : 0;
		f.spc = *p->fmt == ' ' ? 1 : 0;
		p->fmt++;
	}
	p->f = &f;
}
