#include "ft_db.h"

void	print_all(t_db *db)
{
	t_ent	*t;

	t = db->ents;
	while (t)
	{
		printf("For key: %s\nData is: %s\n", t->key, t->data);
		t = t->next;
	}	
}

void	print_ent(t_db *db, char *key)
{
	t_ent	*t;

	t = DE;
	while (t && strcmp(t->key, key) != 0)
		t = t->next;
	if (t)
		printf("For key: %s\nData is: %s\n", t->key, t->data);
	else
		printf("There was no entry for %s\n", key);
}

void	add_ent(t_db *db, char *key, void *data)
{
	t_ent	*t;

	t = db->ents;
	while (t->next)
		t = t->next;
	t->next = init_ent(key, data);
}

void	edit_ent(t_db *db, char *key, void *data)
{
	t_ent	*t;

	t = db->ents;
	while (strcmp(t->key, key) != 0)
		t = t->next;
	if (t)				//need to add in zeeroing before new data
		t->data = data;
}

void	delete_ent(t_db *db, char *key)
{
	t_ent	*t;

	t = db->ents;
	while (strcmp(t->next->key, key) != 0)
		t = t->next;
	t->next = t->next->next;
}

void	delete_all(t_db *db)
{
	t_ent	*t;

	t = db->ents;
	if (t)
		free(t);
	db->ents = NULL;
}
