/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkbrd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:20:11 by sjones            #+#    #+#             */
/*   Updated: 2017/02/21 14:31:42 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_brd	*brdup(t_brd *map)
{
	if (map && (map->l != 0))
		return (ft_mkbrd(map->l + 1));
	return (NULL);
}

void	ft_putbrd(t_brd *map)
{
	char	*m;

	m = map->m;
	while (*m)
	{
		ft_putendl(ft_strndup(m, map->l));
		m += map->l;
	}
}

t_brd	*ft_mkbrd(int c)
{
	t_brd	*b;

	if (!(b = (t_brd*)malloc(sizeof(t_brd))))
		return (NULL);
	if (b)
	{
		if (!(b->m = ft_memalloc(sizeof(char) * c * c + 1)))
			return (NULL);
		ft_memset(b->m, '.', (sizeof(char) * c * c));
		b->l = ft_sqrtr(ft_strlen(b->m));
		b->i = 0;
	}
	return (b);
}
