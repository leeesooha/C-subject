/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:49:21 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/11 00:33:35 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar04(char c)
{
	write(1, &c, 1);
}

int	basecheck(char *base)
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
		if (base[j] == '+' || base[j] == '-')
			return (0);
		j++;
	}
	if (j <= 1)
		return (0);
	return (j);
}

void	itoa(long long bnbr, char *base, int baselength)
{
	int	i;

	i = 0;
	if (bnbr >= baselength)
		itoa(bnbr / baselength, base, baselength);
	ft_putchar04(base[bnbr % baselength]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			baselength;
	long long	bnbr;

	bnbr = (long long)nbr;
	baselength = basecheck(base);
	if (basecheck(base) == 0)
		return ;
	if (bnbr < 0)
	{
		write(1, "-", 1);
		bnbr *= -1;
	}
	itoa(bnbr, base, baselength);
}

#include <stdio.h>
int main(void)
{
	ft_putnbr_base(123,"e76");
}

