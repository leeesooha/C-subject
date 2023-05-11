/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:52:42 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/10 20:19:36 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	check(char *str)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = (k * 10);
		k = k + (str[i] - '0');
		i++;
	}
	return (k);
}

char	*strcheck(char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\r' || *str == '\f')
		str++;
	return (str);
}

int	ft_atoi(char *str)
{
	int	i;
	int	k;
	int	res;

	k = 1;
	i = 0;
	str = strcheck(str);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = check(&str[i]);
			return (res * k);
		}
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f')
			return (0);
		if (!(str[i] == '-' || str[i] == '+'))
			return (0);
		if (str[i] == '-')
			k *= -1;
		i++;
	}
	return (0);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n",ft_atoi("++  ++ "));
}
