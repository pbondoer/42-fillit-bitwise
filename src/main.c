/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:41:37 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/06 06:39:30 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fillit.h"
#include <stdio.h>

void	printbits(t_long v)
{
	int i;

	i = sizeof(t_long) * 8 - 1;
	while (i >= 0)
	{
		ft_putchar('0' + ((v >> i) & 1));
		if (i % 4 == 0) ft_putchar(' ');
		if (i % 16 == 0) ft_putchar('\n');
		i--;
	}
}

void	print(t_etris *tetris, int count)
{
	char *buf;
	int x;
	int y;
	int size;

	size = 16;
	y = 0;
	buf = ft_strnew((size + 1) * (size + 1));
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			buf[y * (size + 1) + x] = '.';
			x++;
		}
		buf[y * (size + 1) + x] = '\n';
		y++;
	}
	while (count > 0)
	{
		printf("%c: %d, %d\n", tetris->id, tetris->x, tetris->y);
		y = 0;
		while (y < tetris->height)
		{
			x = 0;
			while (x < tetris->width)
			{
				if ((tetris->value >> (16 * (y + 1) - 1 - x)) & 1)
					buf[(tetris->y + y) * (size + 1) + x + tetris->x] = tetris->id;
				x++;
			}
			y++;
		}
		tetris++;
		count--;
	}
	ft_putstr(buf);
}
/*
** Utility die function
*/

int		die(char *str)
{
	ft_putendl(str);
	return (1);
}

/*
** Entry point for our application
*/

int		main(int argc, char **argv)
{
	t_etris		tetris[MAX_TETRI + 1];
	short		map[16];
	int			count;

	if (argc != 2)
		return (die("usage: fillit input_file"));
	ft_bzero(tetris, sizeof(t_etris) * (MAX_TETRI + 1));
	if ((count = read_tetri(open(argv[1], O_RDONLY), tetris)) == 0)
		return (die("error"));
	ft_bzero(map, sizeof(short) * 16);
	solve(tetris, count, map);
	print(tetris, count);
	return (0);
}
