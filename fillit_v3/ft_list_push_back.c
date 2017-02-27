/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:31:02 by jeftekha          #+#    #+#             */
/*   Updated: 2017/02/26 16:07:25 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_list_push_back(t_tet **begin_list, void *data)
{
	t_tet	*a;

	a = *begin_list;
	if (*begin_list == '\0')
		*begin_list = ft_newtet(data);
	else
	{
		while (a->next)
			a = a->next;
		a->next = ft_newtet(data);
	}
}
