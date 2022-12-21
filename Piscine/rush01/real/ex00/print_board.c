/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwsong <sunwsong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:40:30 by sunwsong          #+#    #+#             */
/*   Updated: 2022/09/04 23:19:29 by sunwsong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int **board)
{
	char	ch;
	int		i;
	int		j;

	i = 0;
	ch = '0';
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ch += board[i][j];
			write(1, &ch, 1);
			if (j != 3)
				write(1, " ", 1);
			ch -= board[i][j];
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
