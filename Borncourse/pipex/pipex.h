/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:57:09 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/23 18:51:10 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"
//지우고 제출
# include <stdio.h>

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**envppath;
	int		infilefd;
	int		outfilefd;
	int		**pipe;
	char	**cmd;
	int		pipenum;
	int		pipecnt;
}			t_data;

int	main(int argc, char **argv, char **envp);

/*
argument check
*/
int	argscheck(t_data *args);
int	filecheck(t_data *args);

/*
free
*/
int	double_free(char **arg);

#endif
//$@: 현재 Target 이름
//$^: 현재 Target이 의존하는 대상들의 전체 목록
//$?: 현재 Target이 의존하는 대상들 중 변경된 것들의 목록