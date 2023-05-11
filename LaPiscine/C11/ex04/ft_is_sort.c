/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:18:31 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/15 14:24:23 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	left;
	int	right;

	i = 0;
	left = 0;
	right = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) == 0)
		{
			left++;
			right++;
		}
		else if (f(tab[i], tab[i + 1]) > 0)
			left++;
		else if (f(tab[i], tab[i + 1]) < 0)
			right++;
		i++;
	}
	if (left == i || right == i)
		return (1);
	return (0);
}
