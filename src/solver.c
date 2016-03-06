/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:19:32 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/06 07:01:11 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include "fillit.h"
#include <stdio.h>

/*
** Backtracking implementation of the solver.
*/

int		solve_map(t_etris *tetris, int size, short *map)
{
	if (tetris->id == 0)
		return (1);
	tetris->y = 0;
	while (tetris->y <= size - tetris->height)
	{
		tetris->x = 0;
		while (tetris->x <= size - tetris->width)
		{
			if (!(*(t_long *)(map + tetris->y) & (tetris->value >> tetris->x)))
			{
				*(t_long *)(map + tetris->y) ^= tetris->value >> tetris->x;
				if (solve_map(tetris + 1, size, map))
					return (1);
				*(t_long *)(map + tetris->y) ^= tetris->value >> tetris->x;
			}
			tetris->x++;
		}
		tetris->y++;
	}
	return (0);
}

/*
** Tries to solve maps starting from the smallest possible size.
*/

int		solve(t_etris *tetris, int count, short *map)
{
	int		size;

	size = 2;
	while (size * size < count * 4)
		size++;
	while (!solve_map(tetris, size, map) && size <= 16)
	{
		ft_bzero(map, sizeof(short) * 16);
		size++;
	}
	return (size == 17 ? 0 : size);
}
