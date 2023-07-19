#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;
	int		fd3;
	int		fd4;
	int		fd5;
	int		fd6;

	fd3 = open("lowercase_txt", O_RDONLY);
	fd4 = open("uppercase_txt", O_RDONLY);
	fd5 = open("number_txt", O_RDONLY);
	fd6 = open("number&lowercase_txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd3);
		if (str == NULL)
			break ;
		printf("%s", str);
		free(str);
	}
	return (0);
}
