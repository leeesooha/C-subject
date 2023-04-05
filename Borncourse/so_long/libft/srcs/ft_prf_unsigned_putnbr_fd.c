/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prf_unsigned_putnbr_fd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:52:52 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/23 19:14:51 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_putchar(char c, int fd, int *prfcnt)
{
	if (write (fd, &c, 1) == -1)
		return (-1);
	*prfcnt += 1;
	return (1);
}

static int	printnbr(unsigned int n, int fd, int *prfcnt)
{
	if (n >= 10)
		printnbr (n / 10, fd, prfcnt);
	if (*prfcnt < 0)
		return (-1);
	if (ft_putchar ((n % 10) + '0', fd, prfcnt) == -1)
	{
		*prfcnt = -1;
		return (-1);
	}
	return (1);
}

int	ft_prf_unsigned_putnbr_fd(unsigned int n, int fd, int *prfcnt)
{
	if (printnbr(n, fd, prfcnt) == -1)
		return (-1);
	return (1);
}
