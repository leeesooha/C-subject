/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:32:47 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/04 09:50:22 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char *str, char *to_find)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] == to_find[j] && to_find[j])
	{
		j++;
		i++;
	}
	if (to_find[j] == 0)
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[i])
	{	
		if (check(&str[i], to_find) == 1)
			return (&str[i]);
		i++;
	}
	return (0);
}
