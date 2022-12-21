/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwsong <sunwsong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:56:47 by sunwsong          #+#    #+#             */
/*   Updated: 2022/09/04 21:51:40 by sunwsong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_board(int **board);
int		make_board(int row, int col, int **board, int **nums);

int	rvalid_chk(int row, int **rowi, int **board)
{
	int	idx;
	int	num;
	int	cur;
	int	sign;

	sign = 0;
	while (sign < 2)
	{
		idx = (4 - 1) * sign;
		num = 1;
		cur = board[row][(4 - 1) * sign];
		while (board[row][idx] != 4)
		{
			if (cur < board[row][idx])
			{
				cur = board[row][idx];
				num++;
			}
			idx = idx + 1 - (2 * sign);
		}
		if (!(num + 1 == rowi[sign + 2][row] || idx == (4 - 1) * sign))
			return (0);
		sign++;
	}
	return (1);
}

int	cvalid_chk(int col, int **coli, int **board)
{
	int	idx;
	int	num;
	int	cur;
	int	sign;

	sign = 0;
	while (sign < 2)
	{
		idx = (4 - 1) * sign;
		num = 1;
		cur = board[(4 - 1) * sign][col];
		while (board[idx][col] != 4)
		{
			if (cur < board[idx][col])
			{
				cur = board[idx][col];
				num++;
			}
			idx = idx + 1 - 2 * sign;
		}
		if (!(num + 1 == coli[sign][col] || idx == (4 - 1) * sign))
			return (0);
		sign++;
	}
	return (1);
}

int	rep_chk(int row, int col, int val, int **board)
{
	int	idx;

	idx = 0;
	while (idx < 4)
	{
		if (board[idx][col] == val && idx != row)
			return (0);
		idx++;
	}
	idx = 0;
	while (idx < 4)
	{
		if (board[row][idx] == val && idx != col)
			return (0);
		idx++;
	}
	return (1);
}

int	make_board_iter(int row, int col, int **board, int **nums)
{
	int	idx;

	idx = 1;
	while (idx <= 4)
	{
		if (rep_chk(row, col, idx, board) == 1)
		{
			board[row][col] = idx;
			if (make_board(row, col + 1, board, nums) == 1)
				return (1);
			board[row][col] = 0;
		}
		idx++;
	}
	return (0);
}

int	make_board(int row, int col, int **board, int **nums)
{
	int	idx;

	idx = 0;
	if (col == 4)
	{
		if (rvalid_chk(row, nums, board) == 1)
			return (make_board(row + 1, 0, board, nums));
		return (0);
	}
	if (row == 4)
	{
		while (idx < 4)
		{
			if (cvalid_chk(idx, nums, board) == 0)
				return (0);
			idx++;
		}
		print_board(board);
		return (1);
	}
	if (board[row][col] != 0)
	{
		return (make_board(row, col + 1, board, nums));
	}
	return (make_board_iter(row, col, board, nums));
}
