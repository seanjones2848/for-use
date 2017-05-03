#include "ft_db.h"

FILE	*init_db_file(void)
{
	
	FILE *fp = fopen("derpbase.db", "ab+");
	return (fp);
}




void	print_help(void)
{
	puts("commands are:\n-print_all\n-print 'key'\n-add 'key' 'value'\n-edit 'key' 'value'\n-delete 'key'\n-delete_all");
}

void	print_err(void)
{
	printf ("%s\n", "you dun goofed");
	exit (0);
}

void	check_query(int ac, char **av, t_db *db)
{
	int i = 1;
// fix so doesnt seg fault when increments past AV b/c of i++
	ft_putnbr(ac);
	while (i < ac)
	{
		if (strcmp(av[i++], "-help") == 0)
			print_help();
		else if (strcmp(av[i], "-print_all") == 0 && i++)
			print_all(db);
		else if (strcmp(av[i], "-print") == 0 && i++)
			print_ent(db, av[i++]);
		else if (strcmp(av[i], "-add") == 0 && i++)
		{
			add_ent(db, av[i], av[i + 1]);
			i += 2;
		}
		else if (strcmp(av[i], "-edit") == 0 && i++)
		{
			edit_ent(db, av[i], av[i + 1]);
			i += 2;
		}
		else if (strcmp(av[i], "-delete") == 0 && i++)
			delete_ent(db, av[i++]);
		else if (strcmp(av[i], "-delete_all") == 0 && i++)
			delete_all(db);
		else
			print_err();
	}
}

int	main(int ac, char** av)
{
	t_db	*db;

	FILE *fp = fopen("derpbase.db", "r+");
/*	if (fp == NULL)
		fp = init_db_file();
*/	if (ac == 1)
		printf("%s\n", "use -help for help");
	else
	{
		db = init_db(fp);
		fclose(fp);
		check_query(ac, av, db);
		ft_putendl("get here?");
		db_2file(db);
	}
	return(0);
}
