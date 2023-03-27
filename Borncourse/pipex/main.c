/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:37:36 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/27 21:18:16 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;

	creat_envp(&data, argc, argv, envp);
	creat_cmd(&data);
	creat_pipe(&data);
	file_check(&data);
	i = 0;
	while (i <= data.npipe)
	{
		write(2, "debug\n", 6);
		data.pipenum = i;
		child(&data, 0);
		i++;
	}
	waitpid(-1, 0, 0);
//	close(data.pipefd[0][1]);
//	close_child_pipe(&data);
//	waitpid(-1, 0, 0);
//	int wstatus;
//	while (wait(&wstatus) > 0);
//	close(data.outfilefd);
	return (0);
}
