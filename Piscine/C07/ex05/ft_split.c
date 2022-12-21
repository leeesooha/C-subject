/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:55:58 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/15 22:01:09 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*strpush05(char *str, char *charset);
int		strlen05(char *str, char *charset);
char	*strcpy05(char *split, char *str, int strlength);
int		strcnt05(char *str, char *charset, int i, int j);

char	**ft_split(char *str, char *charset)
{
	int		strlength;
	int		i;
	char	**split;
	int		strc;

	strc = strcnt05(str, charset, 0, 0);
	i = 0;
	split = (char **)malloc(sizeof(char *) * (strc + 1));
	if (split == 0)
		return (0);
	while (*str)
	{
		str = strpush05(str, charset);
		strlength = strlen05(str, charset);
		split[i] = (char *)malloc(sizeof(char) * (strlength + 1));
		if (split[i] == 0)
			return (0);
		if (strlength == 0)
			break ;
		split[i] = strcpy05(split[i], str, strlength);
		str += strlength;
		i++;
	}
	split[i] = 0;
	return (split);
}

int	strcnt05(char *str, char *charset, int i, int j)
{
	int	key;
	int	cnt;

	cnt = 0;
	key = 0;
	while (str[i])
	{
		key = 0;
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				key += 1;
				i++;
				j = -1;
			}
			j++;
		}
		if (key >= 1)
			cnt++;
		i++;
	}
	return (cnt + 1);
}

char	*strcpy05(char *split, char *str, int strlength)
{
	int	i;

	i = 0;
	while (i < strlength)
	{
		split[i] = str[i];
		i++;
	}
	split[i] = 0;
	return (split);
}

int	strlen05(char *str, char *charset)
{
	int	i;
	int	j;
	int	key;

	key = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		key = 0;
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				key += 1;
			j++;
		}
		if (key == 1)
			return (i);
		i++;
	}
	return (i);
}

char	*strpush05(char *str, char *charset)
{
	int	i;
	int	key;

	key = 0;
	i = 0;
	while (*str)
	{
		key = 0;
		i = 0;
		while (charset[i])
		{
			if (*str == charset[i])
				key += 1;
			i++;
		}
		if (key == 0)
			return (str);
		str++;
	}
	return (str);
}
#include <stdio.h>

int main(void)
{
	char **str2;
	char str[] = "soo!@has##eoul12!!3succes";
	str2 = ft_split(str, "!@#");
	
	for(int i = 0; i < 4; i++)
	{
		printf("%s\n",str2[i]);
	}
}


