/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prf_putstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:49:09 by soohlee           #+#    #+#             */
/*   Updated: 2023/02/08 23:20:15 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_prf_putstr_fd(char *s, int fd, int *prfcnt)
{
	if (s == 0)
	{
		if (write(fd, "(null)", 6) == -1)
		{
			return (-1);
		}
		*prfcnt += 6;
		return (1);
	}
	if (write(fd, s, ft_prf_strlen(s)) == -1)
		return (-1);
	*prfcnt += ft_prf_strlen(s);
	return (1);
}
