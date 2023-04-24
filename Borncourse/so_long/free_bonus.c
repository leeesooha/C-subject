/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:46:28 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/24 20:32:54 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long_bonus.h"

int	ft_end(t_mlx_data *mlx_db, int idx, int err_flag)
{
	if (mlx_db)
		two_ptr_free(mlx_db->map, idx);
	if (err_flag == ESC || err_flag == SUCCESS
		|| err_flag == STRPUT_MALLOC_ERROR || err_flag == FAIL)
		free_filehash(mlx_db);
	err_print(err_flag);
	return (0);
}

int	err_print(int err_flag)
{
	if (err_flag == ARGS_ERROR)
		ft_printf("Invalid Arguments.\n");
	else if (err_flag == FD_MOLLOC_ERROR || err_flag == STRPUT_MALLOC_ERROR)
		perror("system error");
	else if (err_flag == MAP_CONTENTS_ERROR)
		ft_printf("Error\nInvalid Map's Contents.\n");
	else if (err_flag == NOT_ROUTE)
		ft_printf("No possible route.\n");
	else if (err_flag == FAIL)
	{
		ft_printf("Died\n");
		exit (0);
	}
	else if (err_flag == SUCCESS)
	{
		ft_printf("SUCCESS\n");
		exit (0);
	}
	else
		exit (0);
	exit (1);
	return (0);
}

int	two_ptr_free(char **s, int idx)
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
	free (mlx_db->file[(int) 'O']);
	free (mlx_db->file[(int) 'S']);
	free (mlx_db->file[(int) 'D']);
	free (mlx_db->file);
	return (1);
}
