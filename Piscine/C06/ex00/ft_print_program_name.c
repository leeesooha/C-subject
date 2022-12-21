/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:39:48 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/08 20:17:51 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar00(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	argc = 2;
	i = 0;
	while (argv[0][i])
	{
		ft_putchar00(argv[0][i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
