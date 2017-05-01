#include "ft_db.h"

t_db	*init_db(FILE *fp)
{
	t_db	*db;
	t_entry	*t;

	if (!(db = (t_db*)malloc(sizeof(t_db))))
		return (NULL);
	if (db)
	{
		fp = fopen("derpbase.db", "r+")
		while(fscanf(fp, "%s %s %u", key, data, &len) > 0)
			db->ents = add_ent(key, data, len, db->ents);
	}
	return (db);
}

t_ent	*add_ent(char *key, void *data, size_t len, t_ent *p)
{
	t_entry	*t;

	t = p
	while (t->next)
		t = t->next;
	t->next = init_ent(key, data, len);
	return (p);
}

t_ent	*init_ent(char *key, void *data, size_t len)
{
	t_ent	*ent;

	if(!(ent = (t_ent*)malloc(sizeof(t_ent))))
		return (NULL);
	if(ent)
	{
		ent->key = key;
		ent->data = data;
		ent->len = len;
		enr->next = NULL;
	}
	return (ent);
}
