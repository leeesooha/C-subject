/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:03:43 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/03 21:55:35 by soohlee          ###   ########.fr       */
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
