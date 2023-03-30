/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:57:09 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/30 21:59:38 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./libft/includes/libft.h"
# include <stdio.h>

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**envpaths;
	char	**cmd;
	int		ncmd;
	char	*path_cmd;
	char	**sp_cmd;
	int		pipenum;
	int		**pipefd;
	int		npipe;
	int		hdflag;
	int		infilefd;
	int		outfilefd;
	char	**temp;
}			t_data;

int		main(int argc, char **argv, char **envp);

/*
creat data
*/
int		creat_envp(t_data *data, int argc, char **argv, char **envp);
int		creat_cmd(t_data *data);
int		creat_pipe(t_data *data);
int		file_check(t_data *data);

/*
child
*/
int		child(t_data *data, int pid);
int		infile_to_pipe(t_data *data);
int		pipe_to_outfile(t_data *data);
int		pipe_to_pipe(t_data *data, int current, int next);

/*
cmd_check
*/
int		cmd_check(t_data *data);
char	**cmd_split(t_data *data);

/*
free
*/
int		all_free(t_data *data, int flag, char *s, int errorflag);
int		dpch_free(char **s);
int		pipe_free(int **pipefd);
int		close_pipe(t_data *data);
void	error_print(t_data *data, int errorflag);

/*
here_doc
*/
int		heredoc_chk(t_data *data);
int		heredoc(t_data *data);

#endif
