/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwsong <sunwsong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:18:46 by sunwsong          #+#    #+#             */
/*   Updated: 2022/09/08 12:39:38 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		**init(int **nums);
int		make_board(int row, int col, int **board, int **nums);
void	my_free(int **board, int **nums);

int	arg_chk(char *str)
{
	int	len;
	int	idx;

	len = 0;
	idx = 0;
	while (str[len]) 
		len++;
	if (len != 31)				
		return (0);
	while (idx < len)
	{
		if (idx % 2 == 0)
		{
			if (str[idx] <= '0' || '4' < str[idx])
				return (0);
		}
		else
		{
			if (str[idx] != ' ')
				return (0);
		}
		idx++;
	}
	return (1);
}

int	**alloc_nums(void)
{
	int	i1;
	int	**nums;

	i1 = 0;
	nums = (int **)malloc(sizeof(int *) * 4);
	if (nums == 0)
		return (0);
	while (i1 < 4)
	{
		nums[i1] = (int *)malloc(sizeof(int) * 4);
		if (nums[i1] == 0)
			return (0);
		i1++;
	}
	return (nums);
}

int	**make_nums(char *str)
{
	int	i1;
	int	i2;
	int	**nums;

	nums = alloc_nums();		
	if (nums == 0)
		return (0);
	i1 = 0;
	while (i1 != 4)
	{
		i2 = 0;
		while (i2 != 4)
		{
			nums[i1][i2] = str[i1 * 8 + i2 * 2] - '0';
			i2++;
		}
		i1++;
	}
	return (nums);
}

int	init_board_chk(int **board)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < 4)
	{
		j = 0;
		while (++j < 4)
		{
			k = -1;
			while (++k < j)
			{
				if ((board[i][j] == board[i][k] || board[j][i] == board[k][i])
						&& board[i][j] != 0 && board[j][i] != 0)

			
					return (0);
			}
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	**board;
	int	**nums;

	if (argc != 2)
	{	
		write(1, "Error\n", 6);
		return (0);
	}
	if (arg_chk(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	nums = make_nums(argv[1]);
	board = init(nums);
	if (board == 0 || nums == 0 || init_board_chk(board) == 0)
	{
		write(1, "Error\n", 6);
		return (0); 
	}
	if (make_board(0, 0, board, nums) == 0)
		write(1, "Error\n", 6);
	my_free(board, nums);
	return (0);
}
