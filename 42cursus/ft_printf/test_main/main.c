/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:03:45 by soohlee           #+#    #+#             */
/*   Updated: 2023/05/11 12:16:55 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include "../ft_prf_put_addrhex.c"
#include "../ft_prf_put_hex.c"
#include "../ft_prf_putchar_fd.c"
#include "../ft_prf_putnbr_fd.c"
#include "../ft_prf_putstr_fd.c"
#include "../ft_prf_strlen.c"
#include "../ft_prf_unsigned_putnbr_fd.c"
#include "../ft_printf.c"

int	main(void)
{
	int	return_value;
	int	ft_return_value;

	ft_return_value = ft_printf("Im ft_printf : asdf\n");
	printf("ft_return value : %d\n", ft_return_value);
	write(1, "\n", 1);
	return_value = printf("Im printf : asdf\n");
	printf("return value : %d\n", return_value);
	return (0);
}
