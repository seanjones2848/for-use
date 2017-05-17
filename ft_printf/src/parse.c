#include "../inc/ft_printf.h"

void	parse(t_print *p)
{
	while (*p->fmt != '%')
	{
		ft_putchar(*p->fmt);
		p->ret++;
		p->fmt++;
	}
	init_flags(p);
	
}
