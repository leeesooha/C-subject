/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:26:27 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/25 17:48:02 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	arg_check(int argc, char *argv)
{
	char	*extension;

	if (argc != 2)
		ft_end(0, 0, ARGS_ERROR);
	extension = ft_strchr(argv, '.');
	if (argc != 2 || (extension && ft_strncmp(extension, ".ber\0", 5)))
		ft_end(0, 0, ARGS_ERROR);
	return (0);
}
