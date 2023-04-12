/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:26:27 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/10 11:36:38 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	arg_check(char *argv)
{
	char	*extension;

	extension = ft_strchr(argv, '.');
	if (extension && !ft_strncmp(extension, ".ber", 5))
		return (1);
	return (0);
}
