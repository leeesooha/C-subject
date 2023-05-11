/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:21:46 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/01 12:29:21 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric09(char *str, int n)
{
	int	i;

	i = 0;
	if (!(str[n] >= '0' && str[n] <= '9'))
		return (0);
	return (1);
}

int	ft_str_is_alpha09(char *str, int n)
{
	int	i;

	i = 0;
	if (!(str[n] >= 'a' && str[n] <= 'z'))
		if (!(str[n] >= 'A' && str[n] <= 'Z'))
			return (0);
	return (1);
}

char	*ft_strlowcase09(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

void	check09(char *str, int n)
{	
	if (str[n] >= 'a' && str[n] <= 'z')
	{
		if (ft_str_is_numeric09(str, n - 1) == 0)
		{
			if (ft_str_is_alpha09(str, n - 1) == 0)
			{
				str[n] += 'A' - 'a';
				return ;
			}
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_strlowcase09(str);
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] += 'A' - 'a';
	i = 1;
	while (str[i])
	{
		check09(str, i);
		i++;
	}
	return (str);
}
