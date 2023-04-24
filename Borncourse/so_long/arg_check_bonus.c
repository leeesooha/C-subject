/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:26:27 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/24 19:34:24 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long_bonus.h"

int	arg_check(int argc, char *argv)
{
	char	*extension;

	extension = ft_strchr(argv, '.');
	if (argc != 2 || (extension && ft_strncmp(extension, ".ber\0", 5)))
		ft_end(0, 0, ARGS_ERROR);
	return (0);
}
