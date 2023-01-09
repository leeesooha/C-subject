#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;

	fd = open("Harry Potter.txt", O_RDONLY);
	get_next_line(fd);
	fd = open("The Avengers.txt", O_RDONLY);
	get_next_line(fd);
	fd = open("movie.txt", O_RDONLY);
	get_next_line(fd);
	fd = open("gogo.txt", O_RDONLY);
	get_next_line(fd);
}
