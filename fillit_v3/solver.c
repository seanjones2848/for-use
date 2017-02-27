/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:57:08 by sjones            #+#    #+#             */
/*   Updated: 2017/02/26 16:11:27 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		if_fits(t_brd *b, t_tet *t, char a)
{
	if ((b->i + t->l[3] <= (int)ft_strlen(b->m)) && (b->m[b->i] == '.' &&
		b->m[b->i + t->l[1]] == '.' && b->m[b->i + t->l[2]] == '.' &&
		b->m[b->i + t->l[3]] == '.') && (b->i % b->l >= t->h[0]))
	{
		put_tet(b, t, a);
		if (validate_map(b, a) == 1)
			return (1);
		else
			rm_tet(b, a);
	}
	return (0);
}

void	put_tet(t_brd *b, t_tet *t, char a)
{
	t->s = b->i;
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
		j++;
	}
}

int		solver(t_brd *b, t_tet *t, char a)
{
	b->i = 0;
	if (!t)
		return (1);
	while (b->m[b->i] != '\0')
	{
		if ((if_fits(b, t, a)) == 1)
		{
			if (solver(b, t->next, ++a) == 1)
				return (1);
			else
			{
				rm_tet(b, --a);
				b->i = t->s;
			}
		}
		b->i++;
	}
	return (0);
}

void	solve(t_tet *t)
{
	t_brd	*b;
	char	a;

	a = 'A';
	b = ft_mkbrd(minbrdsize(t));
	set_l(b, t);
	while (solver(b, t, a) != 1)
	{
		b = brdup(b);
		set_l(b, t);
	}
	ft_putbrd(b);
}
