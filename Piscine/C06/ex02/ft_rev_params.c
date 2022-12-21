/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:02:44 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/08 18:56:04 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar02(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argc > 1)
	{
		j = 0;
		while (argv[argc - 1][j])
		{
			ft_putchar02(argv[argc - 1][j]);
			j++;
		}
		write(1, "\n", 1);
		argc--;
	}
	return (0);
}
