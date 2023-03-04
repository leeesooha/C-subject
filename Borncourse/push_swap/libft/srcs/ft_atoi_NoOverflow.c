/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_NoOverflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:46:27 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/02 21:54:18 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static unsigned long long	atoi_check_NoOverflow(const char *str, int flag)
{
	int					i;
	unsigned long long	res;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10);
		res = res + (str[i] - '0');
		if (((res > 2147483647) && (flag == 1)) ||
			((res > 2147483648) && (flag == -1)))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (res);
}

static const char	*str_check_NoOverflow(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\r' || *str == '\f')
		str++;
	return (str);
}

int	ft_atoi_NoOverflow(const char *str)
{
	int	i;
	int	k;
	int	flag;

	flag = 0;
	k = 1;
	i = 0;
	str = (const char *)str_check_NoOverflow(str);
	while (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ((int)(k * atoi_check_NoOverflow(&str[i], k)));
		if (!(str[i] == '-' || str[i] == '+'))
			return (0);
		if (str[i] == '-' || str[i] == '+')
			flag++;
		if (flag > 1)
			return (0);
		if (str[i] == '-')
			k *= -1;
		i++;
	}
	return (0);
}
