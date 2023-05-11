/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:22:52 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/11 21:41:50 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char		*ft_convert_base(char *nbr, char *base_from, char *base_to);
int			ft_atoi_base(char *str, char *base);
int			basecheck05(char *base);
long long	trans05(char *str, char *base, int baselength, long long i);
char		*strcheck05(char *str);

char	*malstr(long midres, long basetolangth)
{
	long	i;
	char	*malstr1;
	long	temp;

	temp = midres;
	if (temp < 0)
		temp *= -1;
	i = 1;
	while (temp >= basetolangth)
	{
		temp = temp / basetolangth;
		i++;
	}
	if (midres < 0)
	{
		malstr1 = (char *)malloc(sizeof(char) * (i = i + 2));
		malstr1[0] = '-';
	}
	else
		malstr1 = (char *)malloc(sizeof(char) * (i = i + 1));
	if (malstr1 == 0)
		return (0);
	malstr1[i - 1] = 0;
	return (malstr1);
}

char	*input(char *resstr, long midres, int basetolangth, char *base_to)
{
	long	temp;
	long	i;

	i = 0;
	if (midres < 0)
	{
		midres *= -1;
		i = 1;
	}
	temp = midres;
	while (temp >= basetolangth)
	{
		temp = temp / basetolangth;
		i++;
	}
	while (midres >= basetolangth)
	{
		resstr[i] = base_to[midres % basetolangth];
		midres = midres / basetolangth;
		i--;
	}
	resstr[i] = base_to[midres % basetolangth];
	return (resstr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	midres;
	int		basetolangth;
	char	*resstr;

	if (basecheck05(base_from) == 0)
		return (0);
	if (base_to == 0)
		return (0);
	basetolangth = basecheck05(base_to);
	if (basecheck05(base_to) <= 1)
		return (0);
	midres = ft_atoi_base(nbr, base_from);
	resstr = malstr(midres, basetolangth);
	if (resstr == 0)
		return (0);
	return (input(resstr, midres, (long)basetolangth, base_to));
}
