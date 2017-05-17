#include "../inc/ft_printf.h"

void	arg_cnt(t_print *p);
{
	char	*tf;
	p->vc = 0;
	tf = p->fmt;
	while (*tf)
	{
		tf = ft_strchr(tf, '%');
		p->vc++;
		if (tf + 1 == '%')
			tf++;
	}
}
