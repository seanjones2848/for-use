int	ft_printf(char *fmt, ...)
{
	t_print	p;

	p.fmt = fmt;
	arg_cnt(&p);
	va_start(p.va, p.vc);
	parse(&p);	
	return(p.ret);
}
