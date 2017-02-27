/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:05:39 by jeftekha          #+#    #+#             */
/*   Updated: 2017/02/26 16:43:34 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(t_tet *tet, int fd)
{
	int		r;
	char	buf[21];
	char	n[1];

	while ((r = read(fd, buf, 20)))
	{
		buf[r] = '\0';
		tet->p = ft_strdup(buf);
		if (validate_tet(tet->p) != 1 || validate_dot(tet->p) != 1)
		{
			ft_putendl("error");
			return (-1);
		}
		if (!((r = read(fd, n, 1)) == 1))
			return (0);
		if (*n != '\n')
		{
			ft_putendl("error");
			return (-1);
		}
		ft_list_push_back(&tet, NULL);
		tet = tet->next;
	}
	ft_putendl("error");
	return (-1);
}
