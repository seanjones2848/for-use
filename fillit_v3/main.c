/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:15:54 by sjones            #+#    #+#             */
/*   Updated: 2017/02/26 16:51:31 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tet	*tet;

	if (!(tet = ft_newtet(NULL)))
		return (0);
	if (ac == 2)
	{
		if (ft_read(tet, open(av[1], O_RDONLY)) == -1)
			return (-1);
		trim(tet);
		solve(tet);
	}
	else
		ft_putendl("usage: ./fillit testfile");
	return (0);
}
