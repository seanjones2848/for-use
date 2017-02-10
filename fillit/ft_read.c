/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:05:39 by jeftekha          #+#    #+#             */
/*   Updated: 2017/02/09 13:59:07 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(t_tet *tet, int fd)
{
	int		r;
	char	buf[21];
	char	n[1];
	t_tet	*head;

	head = tet;
	while ((r = read(fd, buf, 20)))
	{
		buf[r] = '\0';
		tet->p = ft_strdup(buf);
		if (validate(tet) != 1)
			return (-1);
		ft_list_push_back(&tet, NULL);
		tet = tet->next;
		if (!((r = read(fd, n, 1)) == 1))
			return (0);
		if (*n != '\n')
			return (-1);
	}
	return (-1);
}
