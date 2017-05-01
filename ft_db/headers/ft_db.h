#ifndef FT_DB_H
# define FT_BD_H
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <unistd.h>

define struct	s_db
{
size_t		entry_count;
t_ent		*ents;		
}		t_db;

define struct	s_ent
{
char		*key;
void		*data;
size_t		len;
s_ent		*next;
}		t_ent;

FILE		*init_db_file(void);
t_db		*init_db(FILE *fp);
t_ent		*init_ent(char *key, void *data, size_t len);
t_ent		*add_ent(char *key, void *data, size_t len, t_ent *p);
void		print_help(void);
void		print_err(void);
void		check_query(int ac, char **av, t_db db);
void		print_all(FILE *fp);
void		print_db(FILE *fp, char *key);
void		add_db(FILE *fp, char *key, void *data);
void		edit_db(FILE *fp, char *key, void *data);
void		delete_db(FILE *fp, char *key)

#endif
