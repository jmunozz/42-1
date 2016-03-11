/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:13:33 by jmunoz            #+#    #+#             */
/*   Updated: 2016/02/18 11:44:48 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	save_square(t_map **map, int x, int y, int size)
{
	int pos;

	pos = (*map)->width * (*map)->meta->line + (*map)->meta->col;
	if ((*map)->meta->left < size)
	{
		(*map)->meta->left = size;
		(*map)->meta->col = x;
		(*map)->meta->line = y;
	}
	else if ((*map)->meta->left == size && pos > (*map)->width * y + x)
	{
		(*map)->meta->left = size;
		(*map)->meta->col = x;
		(*map)->meta->line = y;
	}
}

int		check_square(t_map **map, int x, int y, int size_max)
{
	t_box	***tab;
	t_meta	*meta;
	int		size;
	int		i;

	tab = (*map)->tab;
	meta = (*map)->meta;
	size = 1;
	i = 0;
	while (i < size_max)
	{
		if (tab[x][y] && get_min(tab[x][y]->nb_left, tab[x][y]->nb_up) >= size)
		{
			save_square(map, x - size + 1, y - size + 1, size);
			size++;
		}
		else
			return (-1);
		x++;
		y++;
		i++;
	}
	return (0);
}

void	do_bsq(t_map **map)
{
	t_box	*box;
	int		min;
	int		i;
	int		stop;
	int		size_max;

	(*map)->meta->col = 0;
	(*map)->meta->line = 0;
	(*map)->meta->left = 0;
	box = (*map)->first;
	while (box && get_min(box->nb_left, box->nb_up) >= (*map)->meta->left)
	{
		stop = -1;
		i = 1;
		min = get_min(box->nb_left, box->nb_up);
		size_max = min;
		while (stop == -1 && min >= (*map)->meta->left)
		{
			stop = check_square(map, box->pos_x - min + i,
					box->pos_y - min + i, size_max--);
			i++;
		}
		box = box->next;
	}
}
