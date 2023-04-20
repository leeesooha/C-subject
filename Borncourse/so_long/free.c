/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:46:28 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/20 16:45:03 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	ft_end(t_mlx_data *mlx_db, int idx, int err_flag)
{
	if (mlx_db)
		two_dimen_free(mlx_db->map, idx);
	if (err_flag == 3 || err_flag == 4)	//flag3 : esc //flag4 : success
		free_filehash(mlx_db);
	err_print(err_flag);
	return (0);
}

int	err_print(int err_flag)
{
	if (err_flag == 0)	//0입력인자오류
		ft_printf("Invalid Arguments.\n");
	else if (err_flag == 1)	//1 fd실패오류 및 malloc 실패오류
		perror("");
	else if (err_flag == 2)	//2map 요소 오류 맵만프리
		ft_printf("Invalid Map's Contents.\n");
	else if (err_flag == 5)
		ft_printf("No possible routes.\n");
	else					//6은 임시 테스트 용(해시파일만들기 전임, 맵프리만함)
		exit (0);
	exit (1);
}

int	two_dimen_free(char **s, int idx)
{
	while (1)
	{
		if (idx == -1)
			break ;
		free(s[idx--]);
	}
	free(s);
	return (1);
}

int	free_filehash(t_mlx_data *mlx_db)
{
	free (mlx_db->file[(int) '0']);
	free (mlx_db->file[(int) '1']);
	free (mlx_db->file[(int) 'c']);
	free (mlx_db->file[(int) 'e']);
	free (mlx_db->file[(int) 'P']);
	free (mlx_db->file[(int) 'S']);
	free (mlx_db->file);
	return (1);
}
