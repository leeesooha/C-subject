/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:48:13 by soohlee           #+#    #+#             */
/*   Updated: 2022/12/21 00:52:45 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strtrim(char *s1, char *set);
char	*find_newline(int fd, char *buffer, ssize_t *bytelength);
char	*ft_substr(char *s, int start, size_t len);
char	*ft_strdup(char *s1);
char	*del_newline(char *resbuffer);

#endif