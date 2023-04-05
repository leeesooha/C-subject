/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:05:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/03 19:20:07 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"

typedef enum e_errstr
{
	NO_FREE = 0,
	FREE	= 1
}	t_errstr;

typedef struct s_config
{
	char	**map;
	int		empty;
	int		wall;
	int		collect;
	int		out;
	int		start;
}	t_config;

/*
so_long
*/
int	main(int argc, char **argv);

/*
map_check
*/
int	map_check(char *argv, char **map);


/*
error & free
*/
int	print_error(int flag);
int	free_double(char **s, int idx);

#endif