/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:39:25 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/11 16:34:22 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

# define MAP meta->map
# define TETRI meta->tetri_tab
# define SIZE meta->size_map
# define NB_TETRI meta->nb_tetri
# define BASE_DEC "0123456789"
# define BASE_TETRI ".#"
# define VALID valid[19][4] = {{15, 0, 0, 0}, {7, 4, 0, 0}, {7, 2, 0, 0},
# define VALID2 {7, 1, 0, 0}, {3, 3, 0, 0}, {6, 3, 0, 0}, {3, 2, 2, 0},
# define VALID3	{3, 1, 1, 0}, {3, 6, 0, 0}, {4, 7, 0, 0}, {2, 3, 2, 0},
# define VALID4 {2, 3, 1, 0}, {2, 2, 3, 0}, {1, 1, 1, 1}, {2, 7, 0, 0},
# define VALID5	{1, 3, 2, 0}, {1, 3, 1, 0}, {1, 1, 3, 0}, {1, 7, 0, 0}}

typedef struct	s_meta
{
	unsigned int	map[32];
	unsigned int	**tetri_tab;
	int				nb_tetri;
	int				size_map;
}				t_meta;

t_meta			*init_meta(void);
void			free_meta(t_meta *meta);
unsigned int	**add_tetri_tab(unsigned int **tab, int size);

void			fillit(t_meta *meta);

void			stick_tetri_up_right(unsigned int *tetri);
void			erase_tetri(t_meta *meta, int i);
void			move_tetri_left(t_meta *meta, int i);

int				open_file(char *file_name);
void			file_to_tab(int	fd, t_meta *meta);
void			verif_tetri(t_meta *meta);
void			map_error(void);

void			print_tab(t_meta *meta);
void			print_meta(t_meta *meta);
void			print_map(t_meta *meta);

#endif
