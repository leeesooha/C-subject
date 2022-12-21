/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunwsong <sunwsong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:56:29 by sunwsong          #+#    #+#             */
/*   Updated: 2022/09/04 23:08:54 by sunwsong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	my_free(int **board, int **nums)
{
	int	idx;

	idx = -1;
	while (++idx < 4)
		free(board[idx]);
	free(board);
	idx = -1;
	while (++idx < 4)
		free(nums[idx]);
	free(nums);
}
