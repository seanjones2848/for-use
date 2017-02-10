/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:31:05 by sjones            #+#    #+#             */
/*   Updated: 2017/02/09 20:49:51 by sjones           ###   ########.fr       */
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
		if (!(t->p = malloc(sizeof(char) * 20)))
			return (NULL);
		if (p == NULL)
			t->p = NULL;
		else
			ft_memcpy((t->p), p, 20);
		t->t = NULL;
		t->h2 = 0;
		t->h3 = 0;
		t->h4 = 0;
		t->next = NULL;
	}
	return (t);
}
