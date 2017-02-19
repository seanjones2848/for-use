/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:57:08 by sjones            #+#    #+#             */
/*   Updated: 2017/02/17 15:40:46 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_l(t_brd *b, t_tet *t)
{
	int		i;

	while (t->next)
	{
		i = 0;
		ft_putnbr(t->h[0]);
		ft_putchar(':');
		ft_putnbr(t->h[1]);
		ft_putchar(':');
		ft_putnbr(t->h[2]);
		ft_putchar(':');
		ft_putnbr(t->h[3]);
		ft_putendl("<- is all of h");
		while (i++ <= 3)
		{
			if (t->h[i] == 1)
				t->l[i] = 1;
			if (t->h[i] == 3 || t->h[i] == 4 || t->h[i] == 5)
				t->l[i] = (t->h[i] + b->l - 5);
		}
		t->l[2] += t->l[1];
		t->l[3] += t->l[2];
		ft_putnbr(t->l[0]);
		ft_putchar(':');
		ft_putnbr(t->l[1]);
		ft_putchar(':');
		ft_putnbr(t->l[2]);
		ft_putchar(':');
		ft_putnbr(t->l[3]);
		ft_putendl("<- is all of l");
		ft_putnbr(b->l);
		ft_putendl("<- with this l");
		if (t->next)
			t = t->next;
	}
}

int		if_fits(t_brd *b, t_tet *t, char a)
{
	if ((b->i + t->l[3] < (int)ft_strlen(b->m)) && (b->m[b->i] == '.' && b->m[b->i + t->l[1]] == '.' &&
		b->m[b->i + t->l[2]] == '.' && b->m[b->i + t->l[3]] == '.'))
	{
	put_tet(b, t, a);
	ft_putbrd(b);
	if (validate_map(b, a) == 1)
		return (1);
	}
	rm_tet(b, a);
	ft_putbrd(b);
	return (0);
}

void	put_tet(t_brd *b, t_tet *t, char a)
{
	b->m[b->i] = a;
	b->m[b->i + t->l[1]] = a;
	b->m[b->i + t->l[2]] = a;
	b->m[b->i + t->l[3]] = a;
}

void	rm_tet(t_brd *b, char a)
{
	int		j;

	j = 0;
	while (j <= (b->l * b->l))
	{
		if (b->m[j] == a)
			b->m[j] = '.';
	}
}

int		solver(t_brd *b, t_tet *t)
{
	char	a;

	a = 'A';
	b->i = 0;
	if (t->next == NULL)
		return (1);
	ft_putstr(b->m);
	ft_putnbr(b->l);
	ft_putnbr(b->i);
	ft_putendl("<- this tuff is the brd");
	while (b->m[b->i] && (b->i < (b->l * b->l)))
	{
		ft_putnbr(b->i);
		ft_putchar(':');
		if (if_fits(b, t, a) == 1)
		{
			ft_putbrd(b);
			if (solver(b, t->next) == 1)
				return (1);
		}
		b->i++;
	}
	return (0);
}

void	solve(t_tet *t)
{
	t_brd	*b;

	b = ft_mkbrd(minbrdsize(t));
	ft_putbrd(b);
	set_l(b, t);
	while (solver(b, t) != 1)
	{
		b = brdup(b);
		ft_memset(t->l, 0, 4);
		set_l(b, t);
	}
	ft_putbrd(b);
}
