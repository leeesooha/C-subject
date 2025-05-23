/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prf_putchar_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:44:43 by soohlee           #+#    #+#             */
/*   Updated: 2023/02/08 23:20:16 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_prf_putchar_fd(char c, int fd, int *prfcnt)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	*prfcnt += 1;
	return (1);
}
