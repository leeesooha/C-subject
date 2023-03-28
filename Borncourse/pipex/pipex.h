/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:57:09 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/28 16:52:33 by soohlee          ###   ########.fr       */
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
	int		hdfd;
	char	**heredoc;
	int		hdflag;
	char	**argv;
	char	**envp;
	char	**envpaths;
	int		infilefd;
	int		outfilefd;
	int		**pipefd;
	char	**cmd;
	char	*path_cmd;
	char	**sp_cmd;
	int		ncmd;
	int		pipenum;
	int		npipe;
}			t_data;

int	main(int argc, char **argv, char **envp);

/*
creat data
*/
int	creat_envp(t_data *data, int argc, char **argv, char **envp);
int	creat_cmd(t_data *data);
int	creat_pipe(t_data *data);
int	file_check(t_data *data);

/*
child
*/
int	child(t_data *data, int pid);
int	infile_to_pipe(t_data *data);
int	pipe_to_outfile(t_data *data);
int	pipe_to_pipe(t_data *data, int current, int next);

/*
cmd_check
*/
int	cmd_check(t_data *data);

/*
parent
*/
int	parent(t_data *data);

/*
free
*/
int	all_free(t_data *data, int flag);
int	dpch_free(char **s);
int	pipe_free(int **pipefd);
int	close_pipe(t_data *data);

/*
here_doc
*/
int	heredoc_chk(t_data *data);
int	heredoc(t_data *data);

#endif
//$@: 현재 Target 이름
//$^: 현재 Target이 의존하는 대상들의 전체 목록
//$?: 현재 Target이 의존하는 대상들 중 변경된 것들의 목록