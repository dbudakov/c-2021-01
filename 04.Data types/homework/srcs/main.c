#include "../includes/libft.h"

int main(int argc, char *argv[])
{
	int i;

	if (argc == 1)
		ft_error(argv, argc, ERR_NON_ARG);

	i = 1;
	while (i < argc)
	{
		if (ft_check(i, argv))
			ft_rar(argv, i);
		if(!g_error)
			if (i != (argc-1))
				printf("\n");
		i++;
	}
	return (g_error);
}
