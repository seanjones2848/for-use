#include "ft_db.h"

void    all_puts(t_ent *ent, FILE *fp)
{
        fputs(ent->key, fp);
        fputc('\n', fp);
        fputs(ent->data, fp);
        fputc('\n', fp);
}

void    db_2file(t_db *db)
{
    FILE    *fp;
    t_ent   *t;

    fp = fopen("derpbase.db", "w+");
    t = db->ents;
    while (t)
    {
        all_puts(t, fp);
        t = t->next;
    }
    fclose(fp);
}

void    print_ent(t_db *db, char *key)
{
    t_ent   *t;

    t = db->ents;
	t = t->next;
    while (t && ft_strcmp(t->key, key) != 0)
        t = t->next;
    if (t)
        printf("For key: %s\nData is: %s\n", t->key, t->data);
    else
        printf("There was no entry for %s\n", key);
}

void    print_all(t_db *db)
{
    t_ent   *t;

    t = db->ents;
    while (t)
    {
        printf("For key: %s\nData is: %s\n", t->key, t->data);
        t = t->next;
    }
}

void    add_ent(t_db *db, char *key, char *data)
{
    t_ent   *t = DE;

    while (t->next)
        t = t->next;
    t->next = init_ent(key, data);
}

void	edit_ent(t_db *db, char *key, char *data)
{
	t_ent	*t = DE;
	char	*str;

    while (t && ft_strcmp(t->key, key) != 0)
		t = t->next;
	if (t)
	{
		str = strdup(t->data);
		t->data = ft_strjoin(str, data);
	}
	else
        printf("There was no entry for %s\n", key);
}

int ft_2dstrlen(char **str, int num)
{
    int i = 0;
    char **tmp;

   tmp = str;
    while (num--)
    {
        i += ft_strlen(*tmp);
        tmp++;
    }
    return (i);
}

char    *ft_strjoindb(t_db *db, int i)
{
    char	*new;
    int		up = 1;
    int		ugh = 0;
    int		count;

   count = ft_atoi(AV[i]);
    i += 2;

   new = ft_strnew(ft_2dstrlen(&AV[i], count) + count);
    if (!new)
        return (NULL);
    while (count >= up)
    {
        while (*AV[i] != '\0')
        {
            *new = *AV[i];
            new++;
            (AV[i])++;
            ugh++;
        }
        *new++ = 30;
        ugh++;
        up++;
		i++;
    }
    new = new - ugh;
    return (new);
}

void	begin_list(t_db *db, char *key, void *data)
{
	t_ent *t;
	
	if (!(DE = ft_memalloc(sizeof(t_ent))))
        return ;
    if(DE)
    {
        DE->key = key;
        DE->data = data;
        DE->next = NULL;
    }
	
}

t_db	*init_db(FILE *fp, int ac, char **av)
{
	t_db	*db;
	char	*tmp;
	char	*tmpk;
	char	*tmpd;
	int		k = 1;

	if (!(db = ft_memalloc(sizeof(t_db))))
		return (NULL);
	if (fp)
	{
		while (get_next_line(fileno(fp), &tmp) > 0)
		{
//			ft_putnbr(k);
			if (k == 1)
			{
				k = 0;
				tmpk = ft_strdup(tmp);
			}
			else
			{
				tmpd = ft_strdup(tmp);
				if (DE == NULL)
					begin_list(db, tmpk, tmpd);
				else
					add_ent(db, tmpk, tmpd);
				k = 1;
			}
		}
	}
	db->ac = ac;
	db->av = cp_av2db(ac, av);
	return (db);
}

t_ent   *init_ent(char *key, void *data)
{
    t_ent   *ent;

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

char	**cp_av2db(int ac, char **av)
{
	char	**ret;
	int		i = 0;

	ret = malloc(sizeof(char*) * (ac + 1));
	ret[ac] = 0;
	while (++i < ac)
		ret[i - 1] = ft_strdup(av[i]);
	return (ret);
}

int ft_print2d(char **array)
{
	char **move;
	int x = 0;
	int y = 0;
	move = array;
		while (move[x])
		{
			y = 0;
			while(move[x][y])
			{
				if (move[x][y] == 'X')
					ft_putchar(move[x][y]);
				else
					ft_putchar(move[x][y]);
				y++;
			}
			ft_putchar('\n');
			x++;
		}
	return (0);
}

void	delete_ent(t_db *db, char *key)
{
	t_ent	*t = DE;

	if (strcmp(t->key, key) == 0)
		DE = t->next;
	else
	{
		while (strcmp(t->next->key, key) != 0)
			t = t->next;
		if (t)
			t->next = t->next->next;
		else
			ft_putendl("There was nothing to delete");
	}
}

void	delete_data(t_db *db, char *key, char *data)
{
	t_ent	*t = DE;

	if (strcmp(t->key, key) == 0)
		t->data = data_rm(t->data, data);
	else
	{
		while (strcmp(t->key, key) != 0)
			t = t->next;
		if (t)
			t->data = data_rm(t->data, data);
		else
			printf("There was no %s to delete", key);
	}
}

char	*data_rm(char *s1, char *s2)
{
	char	*t1;
	char	*t2;
	char	*t3;
	char	*t4;
	char	*ret = s1;
	int		flen;

	t3 = strchr(s2, 30);
	flen = t3 - s2;
	t4 = strndup(s2, flen);

	while (*t4)
	{
		t1 = ft_strstr(ret, t4);
		if (t1)
			{
				flen = t1 - ret;
				t2 = ft_strndup(ret, flen);
				t1 = strchr(t1, 30);
				ret = ft_strjoin(t2, t1);
			}
		if ((t4 = strchr(t3, 30)))
		{
			flen = t4 - t3;
			t4 = strndup(t3 , flen);
			t3 += flen;
		}
		else
		{
			t4 = t3;
			t3 = NULL;
		}
	}
	return (ret);
}

int    check_query(t_db *db)
{
    int		i = 0;
	char	*t;
	
// fix so doesnt seg fault when increments past AV b/c of i++
//
    while (i < (AC - 1))
    {
        if (strcmp(AV[i], "help") == 0)
		{
			i += 1;
			ft_putendl("help is not to be given at the moment");
//			print_help();
        }
		else if (strcmp(AV[i], "print_all") == 0)
		{
			i += 1;
			ft_putendl("printing evrything");
			print_all(db);
		}
		else if (strcmp(AV[i], "print") == 0)
		{
			i += 2;
			printf("printing %s now\n", AV[i - 1]);
            print_ent(db, AV[i - 1]);
		}
        else if (strcmp(AV[i], "add") == 0)
        {
			printf("adding to %s now\n", AV[i + 2]);
			t = ft_strjoindb(db, (i + 1));
            add_ent(db, AV[i + 2], t);
			i += (ft_atoi(AV[i + 1]) + 3);
        }
        else if (strcmp(AV[i], "edit") == 0)
        {
			printf("editing %s now\n", AV[i + 2]);
			t = ft_strjoindb(db, (i + 1));
			edit_ent(db, AV[i + 2], t);
			i += (ft_atoi(AV[i + 1]) + 3);
        }
        else if (strcmp(AV[i], "delete_data") == 0)
		{
			printf("deleting data in %s now\n", AV[i + 2]);
			t = ft_strjoindb(db, (i + 1));
			delete_data(db, AV[i + 2], t);
			i += (ft_atoi(AV[i + 1]) + 3);
		}
        else if (strcmp(AV[i], "delete_ent") == 0)
		{
			i += 2;
			printf("deleting %s now\n", AV[i - 1]);
			delete_ent(db, AV[i - 1]);
		}
        else if (strcmp(AV[i], "delete_all") == 0)
         {
			i += 1;
			ft_putendl("deleting everything");
			//delete_all(db);
		}
        else
		{
         	if (i < (AC - 2))
				i++;
		 	//printf("error");//print_err();
			//return (1);
    	}
	}
	return (0);
}




int main(int ac, char** av)
{
    t_db    *db;

    FILE *fp = fopen("derpbase.db", "r+");
	db = init_db(fp, ac, av);
	fclose(fp);
	if (ac == 1)
        printf("%s\n", "use -help for help");
    else
    {
 //		print_all(db);
     if(check_query(db) == 0)
		printf("done");   
       // db = init_db(fp);
      //  ft_putendl("get here?");
        db_2file(db);

    }
    return(0);
}

