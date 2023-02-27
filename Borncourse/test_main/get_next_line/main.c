#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.c"
#include "get_next_line.h"
#include "get_next_line_utils.c"

int	main(void)
{
	char	*res_str;
	int		fd3, fd4, fd5, fd6, fd7;

	fd3 = open("Harry Potter.txt", O_RDONLY);
	fd4 = open("The Avengers.txt", O_RDONLY);
	fd5 = open("movie.txt", O_RDONLY);
	fd6 = open("gogo.txt", O_RDONLY);
	fd7 = open("test.txt", O_RDONLY);

	res_str = get_next_line(fd3);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd4);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd5);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd3);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd6);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd4);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd5);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd5);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd5);
	printf("%s", res_str);
	free(res_str);
	
	res_str = get_next_line(fd5);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd5);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd7);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd7);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd7);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd7);
	printf("%s", res_str);
	free(res_str);


	res_str = get_next_line(fd3);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd3);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd3);
	printf("%s", res_str);
	free(res_str);

	res_str = get_next_line(fd3);
	printf("%s", res_str);
	free(res_str);


	res_str = get_next_line(fd7);
	while (res_str)
	{		
		printf("%s", res_str);
		free(res_str);
		res_str = get_next_line(fd7);
	}
	res_str = get_next_line(fd7);
	printf("\n%s", res_str);

	printf("%s",get_next_line(fd3));
	printf("%s",get_next_line(fd3));
	printf("%s",get_next_line(fd3));
	printf("%s",get_next_line(fd3));
	printf("%s",get_next_line(fd3));
	printf("%s",get_next_line(fd3));

	return (0);
}
