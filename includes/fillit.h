/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:06:05 by tdupont           #+#    #+#             */
/*   Updated: 2016/03/06 05:23:09 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_TETRI 26
# include <string.h>

typedef unsigned long long t_long;
typedef struct		s_etris
{
	t_long			value;
	char			id;
	unsigned char	x;
	unsigned char	y;
	unsigned char	width;
	unsigned char	height;
}					t_etris;

int					read_tetri(int fd, t_etris *tetris);
int					solve(t_etris *tetris, int count, short *map);
void				printbits(t_long v);
#endif
