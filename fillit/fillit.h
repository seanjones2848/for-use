/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:06:22 by jeftekha          #+#    #+#             */
/*   Updated: 2017/02/09 20:05:44 by sjones           ###   ########.fr       */
/*   Updated: 2017/02/06 14:16:17 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct		s_tet
{
	char			*p;
	char			*t;
	int				h2;
	int				h3;
	int				h4;
	struct s_tet	*next;
}					t_tet;

t_tet	*ft_newtet(char *p);
void	ft_list_push_back(t_tet **begin_list, void *data);
int		ft_read(t_tet *tet, int fd);
int		validate(t_tet *tet);
int		minbrdsize(t_tet *t);
int		ft_sqrtr(int n);
int		ft_lstlen(t_tet *t);
char	*ft_mkbrd(int c);
void	trim(t_tet *tet);

#endif
