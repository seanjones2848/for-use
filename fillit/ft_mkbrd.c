/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkbrd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:20:11 by sjones            #+#    #+#             */
/*   Updated: 2017/02/09 20:49:18 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_mkbrd(int c)
{
	char	*brd;
	char	*t;
	int		n;

	n = c;
	brd = ft_memalloc(sizeof(char) * (c + 1) * c);
	ft_memset(brd, '.', (sizeof(char) * (c + 1) * c));
	t = (brd + c);
	while (n-- > 0)
	{
		*t = '\n';
		t += (c + 1);
	}
	return (brd);
}
