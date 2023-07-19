#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
int		get_buff(char **backup, int fd);
int		get_new_line(char **res_str, char **backup);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1, long long len);
char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*res_str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (get_buff(&backup, fd) == 0)
		return (NULL);
	if (get_new_line(&res_str, &backup) == 0)
		return (NULL);
	return (res_str);
}

int	get_buff(char **backup, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		len;
	char	*temp;

	if (*backup != NULL && ft_strchr(*backup, '\n'))
		return (1);
	while (1)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len < 0 || (len == 0 && *backup == NULL))
		{
			if (*backup)
				free(*backup);
			*backup = NULL;
			return (0);
		}
		if (len == 0 && *backup != NULL)
			break ;
		if (*backup == NULL)
			*backup = ft_strdup("", -1);
		buff[len] = '\0';
		temp = *backup;
		*backup = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(*backup, '\n'))
			break ;
	}
	return (1);
}

int	get_new_line(char **res_str, char **backup)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (ft_strchr(*backup, '\n') == NULL)
	{
		*res_str = *backup;
		*backup = NULL;
		return (1);
	}
	while ((*backup)[i] != '\n')
		i++;
	*res_str = ft_strdup(*backup, i + 1);
	temp = *backup;
	if (ft_strlen(ft_strchr(temp, '\n') + 1) == 0)
		*backup = NULL;
	else
		*backup = ft_strdup(ft_strchr(temp, '\n') + 1, -1);
	free(temp);
	return (1);
}

char	*ft_strdup(const char *s1, long long len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (len != -1)
	{
		str = (char *)malloc(len + 1);
		while (s1[i] && len--)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	str = (char *)malloc(ft_strlen(s1) + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		n++;
		s++;
	}
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s1;
	char	c1;

	s1 = (char *)s;
	c1 = (char)c;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == c1)
			return ((char *)s1 + i);
		i++;
	}
	if (c1 == 0)
		return ((char *)s1 + i);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1[j])
		new_str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}
