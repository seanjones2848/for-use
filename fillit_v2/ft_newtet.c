/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:31:05 by sjones            #+#    #+#             */
/*   Updated: 2017/02/15 01:39:08 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*ft_newtet(char *p)
{
	t_tet	*t;

	if (!(t = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	if (t)
	{
		if (!(t->p = ft_memalloc(sizeof(char) * 20)))
			return (NULL);
		if (!(t->h = ft_memalloc(sizeof(int) * 4)))
			return (NULL);
		if (!(t->l = ft_memalloc(sizeof(int) * 4)))
			return (NULL);
		if (p == NULL)
			t->p = NULL;
		else
			ft_memcpy((t->p), p, 20);
		t->t = NULL;
		t->next = NULL;
	}
	return (t);
}
