/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:57:09 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/24 18:54:18 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"
//지우고 제출
# include <stdio.h>

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**envpaths;
	int		infilefd;
	int		outfilefd;
	int		**pipefd;
	char	**cmd;
	char	**full_namecmd;
	int		cmd_total;
	int		pipenum;
	int		pipe_total;
}			t_data;

int	main(int argc, char **argv, char **envp);

/*
creat data
*/
int	creat_envp(t_data *args, int argc, char **argv, char **envp);
int	creat_cmd(t_data *args);
int	creat_pipe(t_data *args);

/*
child
*/
int	child(t_data *args, int pid);
int	infile_to_pipe(t_data *args, char *filename);
int	pipe_to_outfile(t_data *args, char *filename);
int	redirection(t_data *args, int current, int next);

/*
parent
*/
int parent(t_data *args);

/*
cmd check
*/
int cmd_check(t_data *args, char *cmd);
int space_idx(char *cmd);
/*
free
*/
int	all_free(t_data *args, int flag);
int	dpch_free(char **s);
int	pipe_free(int **pipefd);
int	close_child_pipe(t_data *args);

#endif
//$@: 현재 Target 이름
//$^: 현재 Target이 의존하는 대상들의 전체 목록
//$?: 현재 Target이 의존하는 대상들 중 변경된 것들의 목록