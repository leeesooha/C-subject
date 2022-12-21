/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwsong <sunwsong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:06:53 by sunwsong          #+#    #+#             */
/*   Updated: 2022/09/07 20:48:58 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	init_col_up(int *colup, int **board)
{
	int	col;
	int	row;

	row = 0;
	col = 0;
	while (col < 4)
	{
		if (colup[col] == 1)
			board[0][col] = 4;
		else if (colup[col] == 4)
		{
			while (row < 4)
			{
				board[row][col] = row + 1;
				row++;
			}
		}
		col++;
	}
}

void	init_col_down(int *cold, int **board)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (col < 4)
	{
		if (cold[col] == 1)
			board[4 - 1][col] = 4;
		else if (cold[col] == 4)
		{
			while (row < 4)
			{
				board[row][col] = 4 - row;
				row++;
			}
		}
		col++;
	}
}

int	init_row_left(int	*rowl, int	**board)
{
	int	row;
	int	col;

	row = 0;
	col = -1;
	while (row < 4)
	{
		if (rowl[row] == 1)
		{
			if (board[row][0] != 0 && board[row][0] != 4)		//틀렸을 때 대비 위에서 정확한거 넣어줬는데 그게 틀렸을 때 는 리턴 0
				return (0);
			board[row][0] = 4;
		}
		else if (rowl[row] == 4)
		{
			while (++col < 4)
			{
				if (board[row][col] != 0 && board[row][col] != col + 1)
					return (0);
				board[row][col] = col + 1;
			}
		}
		row++;
	}
	return (1);
}

int	init_row_right(int	*rowr, int	**board)
{
	int	row;
	int	col;

	row = 0;
	col = -1;
	while (row < 4)
	{
		if (rowr[row] == 1)
		{
			if (board[row][4 - 1] != 0 && board[row][4 - 1] != 4)
				return (0);
			board[row][4 - 1] = 4;
		}
		else if (rowr[row] == 4)
		{
			while (++col < 4)
			{
				if (board[row][col] != 0 && board[row][col] != 4 - col)
					return (0);
				board[row][col] = 4 - col;
			}
		}
		row++;
	}
	return (1);
}

int	**init(int **nums)
{
	int	**board;
	int	i1;
	int	i2;

	i1 = 0;
	board = (int **)malloc(sizeof(int *) * 4);
	if (board == 0)
		return (0);
	while (i1 < 4)
	{
		board[i1] = (int *)malloc(sizeof(int) * 4);
		if (board[i1++] == 0)
			return (0);
	}
	while (--i1 >= 0)
	{
		i2 = 0;
		while (i2 < 4)
			board[i1][i2++] = 0;		//16칸을 0으로 채움
	}
	init_col_up(nums[0], board);
	init_col_down(nums[1], board);
	if (init_row_left(nums[2], board) + init_row_right(nums[3], board) != 2)
		return (0);
	return (board);
}
