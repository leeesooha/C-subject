/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:53:34 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/15 00:31:07 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *) s1;
	a2 = (unsigned char *) s2;
	i = 0;
	while (a1[i] && a2[i])
	{
		if (a1[i] != a2[i])
		{
			return (a1[i] - a2[i]);
		}
		i++;
	}
	return (a1[i] - a2[i]);
}

void	ft_chagne(char **tab, int l)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (i < l - 1)
	{
		j = i + 1;
		if (ft_strcmp(tab[i], tab[j]) > 0)
		{
			str = tab[i];
			tab[i] = tab[j];
			tab[j] = str;
		}
		i++;
	}
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (tab[l])
		l++;
	while (i < l - 1)
	{
		ft_chagne(tab, l);
		l--;
	}
}
