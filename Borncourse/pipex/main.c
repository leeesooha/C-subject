/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:37:36 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/31 00:45:54 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;

	if (argc <= 4)
		exit (1);
	creat_envp(&data, argc, argv, envp);
	creat_cmd(&data);
	creat_pipe(&data);
	file_check(&data);
	i = 0;
	data.pipenum = i;
	while (i <= data.npipe)
	{
		child(&data, 0);
		i++;
		data.pipenum = i;
	}
	close_pipe(&data);
	while (wait(0) > 0)
		write(1, "", 0);
	unlink(".here_doc_tmp");
	all_free(&data, 3, 0, 10);
	return (0);
}
