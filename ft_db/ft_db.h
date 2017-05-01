#ifndef FT_DB_H
# define FT_BD_H
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <unistd.h>

define struct	s_db
{
size_t		entry_count;
t_entry		*entries;		
}		t_db;

define struct	s_entry
{
char		*name;
void		**data;
size_t		len;
s_entry		*next;
}		t_entry;

#endif
