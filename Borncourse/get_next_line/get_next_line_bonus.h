/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:10:50 by soohlee           #+#    #+#             */
/*   Updated: 2023/01/13 10:08:11 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_fileinfo
{
	int					fd;
	char				*backup;
	struct s_fileinfo	*next;
}						t_fileinfo;
char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len, int e);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strchr(const char *s, int c);

#endif