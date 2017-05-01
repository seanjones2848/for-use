#include "ft_db.h"

FILE	*init_db(void)
{
	return (fopen("derpbase.db", "ab+"));
}

void	print_help(void)
{
	printf("%s\n", "commands are:\n
		-print_all\n
		-print 'key'\n
		-add 'key' 'value'\n
		-edit 'key' 'value'\n
		-delete 'key'");
}

void	print_err(void)
{
	printf ("%s\n", "you dun goofed");
	exit ();
}

void	check_query(int ac, char **av, FILE *fp)
{
	int i = 2;

	while (i <= ac)
	{
		if (strcmp(av[i], "-help") == 0)
			print_help();
		else if (strcmp(av[i], "-print_all") == 0 && i++)
			print_all(fp);
		else if (strcmp(av[i], "-print") == 0 && i++)
			print_db(fp, av[i++]);
		else if (strcmp(av[i], "-add") == 0 && i++)
			add_db(fp, av[i++], av[i++]);
		else if (strcmp(av[i], "-edit") == 0 && i++)
			edit_db(fp, av[i++], av[i++]);
		else if (strcmp(av[i++], "-delete") == 0 && i++)
			delete_db(fp, av[i++]);
		else
			print_err();
		if (i < ac)
			i++;
	}
}

int	main(int ac, char** av)
{
	FILE *fp = fopen("derpbase.db", "r+");
	if (fp == NULL)
		fp = init_db();
	if (ac == 1)
		printf("%s\n", "use -help for help")
	else
		check_query(ac, av, fp)
	return(0);
}


