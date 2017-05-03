#include "ft_db.h"

int		ent_len(t_db *db)
{
	int	i = -1;
	
	while (DE && i++)
		DE = DE->next;
	return (i);
}
