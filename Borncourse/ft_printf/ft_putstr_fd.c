/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:49:09 by soohlee           #+#    #+#             */
/*   Updated: 2022/12/09 19:46:44 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd, int *prfcnt)
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
	if (write(fd, s, ft_strlen(s)) == -1)
		return (-1);
	*prfcnt += ft_strlen(s);
	return (1);
}
