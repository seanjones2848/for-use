#include "ft_db.h"

t_db	*init_db(FILE *fp)
{
	t_db	*db;
	char	*tmp;
	char	*tmpk;
	char	*tmpd;
	int		k = 1;

	if (!(db = ft_memalloc(sizeof(t_db))))
		return (NULL);
	if (!(DE = ft_memalloc(sizeof(t_ent))))
		return (NULL);
	DE = init_ent(0,0);
	if (fp)
	{
		while (get_next_line(fileno(fp), &tmp) > 0)
		{
			ft_putnbr(k);
			if (k == 1 && k--)
				tmpk = ft_strdup(tmp);
			else
			{
				tmpd = ft_strdup(tmp);
				add_ent(db, tmpk, tmpd);
				k++;
			}
		}
	}
	return (db);
}

t_ent	*init_ent(char *key, void *data)
{
	t_ent	*ent;

	if(!(ent = (t_ent*)malloc(sizeof(t_ent))))
		return (NULL);
	if(ent)
	{
		ent->key = key;
		ent->data = data;
		ent->next = NULL;
	}
	return (ent);
}
