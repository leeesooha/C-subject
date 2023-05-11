/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:15:03 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/17 20:03:26 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_content(void *content)
{
	free(content);
	return (0);
}

int	do_not(void *content)
{
	if (content)
		return (0);
	return (0);
}
