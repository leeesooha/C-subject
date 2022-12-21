/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:08:55 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/13 00:09:59 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

char	*malstr(char *str, int len)
{
	int		i;
	char	*resstr;

	i = 0;
	resstr = (char *)malloc(sizeof(char) * (len + 1));
	if (resstr == 0)
		return (0);
	while (str[i])
	{
		resstr[i] = str[i];
		i++;
	}
	resstr[i] = 0;
	return (resstr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			len;
	t_stock_str	*a;

	a = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		a[i].size = len;
		a[i].str = av[i];
		a[i].copy = malstr(a[i].str, len);
		i++;
	}
	a[i].str = 0;
	return (a);
}
