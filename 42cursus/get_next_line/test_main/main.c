/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:57:03 by soohlee           #+#    #+#             */
/*   Updated: 2023/05/11 12:02:37 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "../get_next_line.c"
#include "../get_next_line.h"
#include "../get_next_line_utils.c"

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

	str = get_next_line(fd3);
	printf("%s", str);
	free(str);

	str = get_next_line(fd4);
	printf("%s", str);
	free(str);

	str = get_next_line(fd5);
	printf("%s", str);
	free(str);

	str = get_next_line(fd3);
	printf("%s", str);
	free(str);

	str = get_next_line(fd6);
	printf("%s", str);
	free(str);

	str = get_next_line(fd4);
	printf("%s", str);
	free(str);

	str = get_next_line(fd5);
	printf("%s", str);
	free(str);

	str = get_next_line(fd5);
	printf("%s", str);
	free(str);

	str = get_next_line(fd5);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd5);
	printf("%s", str);
	free(str);

	str = get_next_line(fd5);
	printf("%s", str);
	free(str);

	str = get_next_line(fd3);
	printf("%s", str);
	free(str);

	str = get_next_line(fd3);
	printf("%s", str);
	free(str);

	str = get_next_line(fd3);
	printf("%s", str);
	free(str);

	str = get_next_line(fd3);
	printf("%s", str);
	free(str);

	while (str)
	{		
		str = get_next_line(fd3);
		printf("%s", str);
		free(str);
	}
	str = get_next_line(fd3);
	printf("\n%s", str);
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd3));
	return (0);
}
