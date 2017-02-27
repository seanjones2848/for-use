/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:36:35 by sjones            #+#    #+#             */
/*   Updated: 2017/02/26 16:07:01 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		trim_help(char *t)
{
	int		c;

	c = 1;
	while (*t && c < 6)
	{
		if (*t == '#')
			return (c);
		c++;
		t++;
	}
	return (0);
}

void	trim(t_tet *tet)
{
	char	*t;
	int		i;

	while (tet)
	{
		i = 1;
		t = (ft_strchr(tet->p, '#')) + 1;
		while (i <= 3)
		{
			tet->h[i] = trim_help(t);
			t = (ft_strchr(t, '#')) + 1;
			i++;
		}
		if (tet->h[1] == 3)
			tet->h[0] = 2;
		if (tet->h[1] == 4 || (tet->h[3] == 4 && tet->h[1] != 1 && tet->h[1]
			!= 5) || (tet->h[1] == 5 && tet->h[2] == 4))
			tet->h[0] = 1;
		tet = tet->next;
	}
}
