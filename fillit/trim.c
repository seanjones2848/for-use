/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:36:35 by sjones            #+#    #+#             */
/*   Updated: 2017/02/09 20:48:17 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		trim_help(char *t, int h)
{
	int		c;

	c = 1;
	while (*t && (h == 0))
	{
		if (*t++ == '#')
			return (c);
		c++;
	}
	return (0);
}

void	trim(t_tet *tet)
{
	char	*t;

	while (tet->next)
	{
		t = (ft_strchr(tet->p, '#') + 1);
		tet->h2 = trim_help(t, tet->h2);
		t = (ft_strchr(t, '#') + 1);
		tet->h3 = trim_help(t, tet->h3);
		t = (ft_strchr(t, '#') + 1);
		tet->h4 = trim_help(t, tet->h4);
		tet = tet->next;
	}
}
