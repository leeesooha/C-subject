/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 20:13:23 by soohlee           #+#    #+#             */
/*   Updated: 2022/08/28 22:46:02 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	output_char(int row, int column, int x, int y)
{
	char	c;

	c = ' ';
	if (column == x)
		c = '*';
	if (row == y)
		c = '*';
	if (column == 1)
		c = '*';
	if (row == 1)
		c = '*';
	if (row == y && column == x)
		c = '/';
	if (row == y && column == 1)
		c = '\\';
	if (row == 1 && column == x)
		c = '\\';
	if (row == 1 && column == 1)
		c = '/';
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
