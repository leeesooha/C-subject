/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:57:05 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/15 02:19:53 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print(int res);
void	midcal(int a, int b, char *str);

int	errorchk(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (!(argv[2][0] == '+' || argv[2][0] == '-' || argv[2][0] == '/'
		|| argv[2][0] == 42 || argv[2][0] == '%'))
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (argv[2][0] == '/' && argv[3][0] == '0')
	{	
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (argv[2][0] == '%' && argv[3][0] == '0')
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	k;
	int	sign;

	sign = 1;
	k = 0;
	i = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = (k * 10);
		k = k + (str[i] - '0');
		i++;
	}
	return (k * sign);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	void	(*fp)(int, int, char *);

	fp = midcal;
	if (errorchk(argc, argv) == 0)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	fp(a, b, argv[2]);
	write(1, "\n", 1);
	return (0);
}
