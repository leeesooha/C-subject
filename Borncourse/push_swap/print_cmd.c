/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:15:03 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/14 18:08:53 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_cmd(t_list **cmd)
{
	t_list	*temp_cmd;
	char	*temp_str;

	temp_cmd = *cmd;
	while (temp_cmd)
	{
		temp_str = (char *)temp_cmd->content;
		write(1, temp_str, ft_strlen(temp_str));
		write(1, "\n", 1);
		temp_cmd = temp_cmd->next;
	}
	ft_lstclear(cmd, (void *)free_content);
	return (0);
}

int	free_content(void *content)
{
	free(content);
	return (0);
}
