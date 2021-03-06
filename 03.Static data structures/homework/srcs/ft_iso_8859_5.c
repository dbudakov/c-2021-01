#define ISO_8859_5
#include "../includes/libft.h"

int ft_iso_8859_5(char *argv[])
{
	int a;
	int num;
	int buff;
	FILE *in_stream;
	FILE *to_stream;

	// open file read
	if ((in_stream = fopen(argv[1], "r")) == NULL)
	{
		ft_error(argv, errno);
	}
	a = getc(in_stream);
	if (a == -1)
		ft_error(argv, ERR_EMPTY_FILE);

	if ((to_stream = fopen(argv[3], "w")) == NULL)
	{
		argv[1] = argv[3];
		ft_error(argv, errno);
	}

	while (a != -1)
	{
		if (a > 175 && a < 240)
		{
			num = a - 176;
			buff = iso_8859_5[num];
			if (buff > 127 && buff < 144)
				fputc(209, to_stream);
			else if (buff > 143 && buff < 192)
				fputc(208, to_stream);
			fputc(buff, to_stream);
		}
		else
			fputc(a, to_stream);
		a = getc(in_stream);
	}

	fclose(in_stream);
	fclose(to_stream);
	return 0;
}
