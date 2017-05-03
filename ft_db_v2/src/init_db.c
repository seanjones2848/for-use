#include "ft_db.h"

t_db	*init_db(FILE *fp)
{
	t_db	*db;
	char	*tmpk = 0;
	char	*tmpd = 0;

	if (!(db = ft_memalloc(sizeof(t_db))))
		return (NULL);
	if (!(DE = ft_memalloc(sizeof(t_ent))))
		return (NULL);
	DE = init_ent(0,0);
	if (fp)
	{
		fp = fopen("derpbase.db", "r+");// maybe not needed open	
		while(fscanf(fp, "%s %s", tmpk, tmpd) > 0) //take out length
			add_ent(db, tmpk, tmpd);
		//close file maybe
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
