/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:32:59 by sjones            #+#    #+#             */
/*   Updated: 2017/02/26 16:40:18 by sjones           ###   ########.fr       */
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
	int				*h;
	int				*l;
	int				s;
	struct s_tet	*next;
}					t_tet;

typedef struct		s_brd
{
	char			*m;
	int				i;
	int				l;
}					t_brd;

t_tet				*ft_newtet(char *p);
void				ft_list_push_back(t_tet **begin_list, void *data);
int					ft_read(t_tet *tet, int fd);
int					validate_tet(char *t);
int					validate_dot(char *t);
int					validate_map(t_brd *b, char a);
int					minbrdsize(t_tet *t);
int					ft_sqrtr(int n);
int					ft_lstlen(t_tet *t);
t_brd				*ft_mkbrd(int c);
t_brd				*brdup(t_brd *map);
void				trim(t_tet *tet);
int					trim_help(char *t);
int					if_fits(t_brd *b, t_tet *t, char a);
void				put_tet(t_brd *b, t_tet *t, char a);
void				rm_tet(t_brd *b, char a);
void				solve(t_tet *t);
int					solver(t_brd *b, t_tet *t, char a);
void				ft_putbrd(t_brd *map);
void				set_l(t_brd *b, t_tet *t);

#endif
