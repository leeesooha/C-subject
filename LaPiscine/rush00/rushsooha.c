/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushsooha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:18:45 by soohlee           #+#    #+#             */
/*   Updated: 2022/08/30 13:23:16 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rush(int x,int y)
{
	int	row;
	int column;
	char c;

	if (x <= 0 || y <= 0)
		return ;
	row = 1;
	while (row <= y)
	{
		coulum = 1;
		while (column <= x)
		{
			
