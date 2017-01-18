/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:06:05 by tdupont           #+#    #+#             */
/*   Updated: 2017/01/18 00:56:27 by lemon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_TETRI 26
# include <string.h>
# include <stdint.h>

typedef struct		s_etris	t_etris;

typedef struct		s_etris
{
	uint64_t			value;
	t_etris				*last;
	unsigned char		id;
	unsigned char		x;
	unsigned char		y;
	unsigned char		width;
	unsigned char		height;
}					t_etris;

int					read_tetri(const int fd, t_etris *tetris);
int					solve(t_etris *tetris, const int count, uint16_t *map);
int					check_piece(const t_etris *tetris, uint16_t *map);
void				toggle_piece(const t_etris *tetris, uint16_t *map);
#endif
