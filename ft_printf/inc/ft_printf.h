#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define F p->f
# define VC p->vc
# define VA p->va

typedef struct		s_print
{
char			*fmt;
int			vc;
va_list			va;
int			ret;
t_flags			*f;
}			t_print

typedef struct		s_flags
{
int			hash:1;
int			zero:1;
int			neg:1;
int			pos:1;
int			spc:1;
int			width;
int			prec;
}			t_flags;

void			arg_cnt(t_print *p);
void			parse(t_print *p);
void			init_flags(t_print *p);
int			is_conv(char c);

# endif
