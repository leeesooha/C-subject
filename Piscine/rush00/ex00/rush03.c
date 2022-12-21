/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 20:13:33 by soohlee           #+#    #+#             */
/*   Updated: 2022/08/28 22:46:44 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	output_char(int row, int column, int x, int y)
{
	char	c;

	c = ' ';
	if (column == x)
		c = 'B';
	if (row == y)
		c = 'B';
	if (column == 1)
		c = 'B';
	if (row == 1)
		c = 'B';
	if (row == y && column == x)
		c = 'C';
	if (row == y && column == 1)
		c = 'A';
	if (row == 1 && column == x)
		c = 'C';
	if (row == 1 && column == 1)
		c = 'A';
	return (c);
}

void	rush(int x, int y)
{
	int		row;
	int		column;
	char	c;

	if (x <= 0 || y <= 0)
		return ;
	row = 1;
	while (row <= y)
	{
		column = 1;
		while (column <= x)
		{
			c = output_char(row, column, x, y);
			ft_putchar(c);
			column++;
		}
		c = '\n';
		ft_putchar(c);
		row++;
	}
}
