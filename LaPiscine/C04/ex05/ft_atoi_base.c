/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:16:09 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/11 00:30:15 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int			basecheck05(char *base);
long long	trans05(char *str, char *base, int baselength, long long i);
char		*strcheck05(char *str);

int	ft_atoi_base(char *str, char *base)
{
	long long	sign;
	long long	res;

	sign = 1;
	str = strcheck05(str);
	if (basecheck05(base) == 0)
		return (0);
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = trans05(str, base, basecheck05(base), 0) * sign;
	return ((int)res);
}

int	basecheck05(char *base)
{
	int	i;
	int	j;

	j = 0;
	while (base[j])
	{
		i = j + 1;
		while (base[i])
		{
			if (base[j] == base[i])
				return (0);
			i++;
		}
		if (base[j] == '+' || base[j] == '-' || base[j] == ' ')
			return (0);
		if (base[j] == '\n' || base[j] == '\t' || base[j] == '\v')
			return (0);
		if (base[j] == '\f' || base[j] == '\r')
			return (0);
		j++;
	}
	if (j <= 1)
		return (0);
	return (j);
}

char	*strcheck05(char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\r' || *str == '\f')
		str++;
	return (str);
}

long long	trans05(char *str, char *base, int baselength, long long i)
{
	long long	j;
	long long	res;
	int			key;

	key = 0;
	res = 0;
	j = -1;
	while (str[++j])
	{
		i = 0;
		key = 0;
		while (base[i])
		{
			if (str[j] == base[i])
			{
				res = res * baselength;
				res = res + i;
				key += 1;
			}
			i++;
		}
		if (key == 0)
			break ;
	}
	return (res);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n",ft_atoi_base("","0123456789"));
}

