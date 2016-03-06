/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:41:37 by pbondoer          #+#    #+#             */
/*   Updated: 2016/03/06 04:09:08 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fillit.h"
#include <stdio.h>

void	printbits(long long v)
{
	int i;

	i = sizeof(long long) * 8;
	while (i > 0)
	{
		i--;
		ft_putchar('0' + ((v >> i) & 1));
		if (i % 4 == 0) ft_putchar(' ');
		if (i % 16 == 0) ft_putchar('\n');
	}
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
	t_etris		tetris[MAX_TETRI];
	//short		*map;
	int i;

	if (argc != 2)
		return (die("usage: fillit input_file"));
	if (read_tetri(open(argv[1], O_RDONLY), (&tetris[0])))
		return (die("error"));
	i = 0;
	while (i < 4)
	{
		printf("%d -> %c (%d, %d, %lld)\n", i, tetris[i].id, tetris[i].width, tetris[i].height, tetris[i].value);
		printbits(tetris[i].value);
		ft_putchar('\n');
		i++;
	}
	//map = solve(tetris);
	//print_map(map);
	return (0);
}
