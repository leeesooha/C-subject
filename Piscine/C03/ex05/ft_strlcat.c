/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:32:20 by soohlee           #+#    #+#             */
/*   Updated: 2022/09/04 14:11:13 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	dst_plus_src;

	k = 0;
	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	dst_plus_src = i + j;
	if (i > size)
		return (j + size);
	j = i;
	while (size > j + 1 && src[k])
	{
		dest[i] = src[k];
		size--;
		k++;
		i++;
	}
	dest[i] = 0;
	return (dst_plus_src);
}
