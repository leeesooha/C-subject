/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:28:18 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/15 01:23:46 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		l;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	l = 0;
	while (tab[l])
		l++;
	while (0 < l - 1)
	{
		j = 0;
		while (j < l - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				str = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = str;
			}
			j++;
		}
		l--;
	}
}
