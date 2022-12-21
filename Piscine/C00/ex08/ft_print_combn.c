/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:52:20 by soohlee           #+#    #+#             */
/*   Updated: 2022/08/27 18:04:11 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_combn(char c)
{
	write (1, &c, 1);
}

void	check2(int *abc, int n)
{
	int	i;
	int	k;

	k = 1;
	i = n - 2;
	while (abc[i] == 9 - k)
	{
		i--;
		k++;
	}
	abc[i] += 1;
	i++;
	while (i < n)
	{
		abc[i] = abc[i - 1] + 1;
		i++;
	}
}

void	check(int *abc, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (abc[i] > 9)
		{
			if (abc[i - 1] == abc[i] - 2)
				check2 (abc, n);
			else
			{
				abc[i - 1] += 1;
				abc[i] = abc[i - 1] + 1;
			}
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	abc[10];

	i = -1;
	while (++i < n)
		abc[i] = i;
	while (abc[0] <= 10 - n)
	{
		check(abc, n);
		i = 0;
		while (i < n)
		{
			ft_putchar_combn(abc[i] + '0');
			i++;
		}
		if (abc[0] != 10 - n)
			write(1, ", ", 2);
		else if (abc[0] == 10 - n)
			return ;
		abc[n - 1] += 1;
	}
}
