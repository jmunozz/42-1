/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 18:43:19 by jubarbie          #+#    #+#             */
/*   Updated: 2016/02/18 11:53:45 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	box_clear(t_map **map)
{
	t_box	*p;
	t_box	*del;

	p = (*map)->first;
	if (p != NULL)
		while (p->next)
		{
			del = p;
			p = p->next;
			free(del);
		}
	free(p);
	(*map)->first = NULL;
}

int		get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_box	*do_box(int pos_x, int pos_y, int nb_left, int nb_up)
{
	t_box	*box;

	box = (t_box*)malloc(sizeof(t_box));
	box->next = NULL;
	box->pos_x = pos_x;
	box->pos_y = pos_y;
	box->nb_left = nb_left;
	box->nb_up = nb_up;
	return (box);
}

t_box	*insert_sort_box(t_map **map, t_box *box)
{
	t_box	*first;

	if ((*map)->first == NULL)
		(*map)->first = box;
	else
	{
		first = (*map)->first;
		if (get_min(box->nb_left, box->nb_up) >
			get_min(first->nb_left, first->nb_up))
		{
			box->next = first;
			(*map)->first = box;
		}
		else
		{
			while (first->next && get_min(box->nb_left, box->nb_up) <=
				get_min(first->next->nb_left, first->next->nb_up))
				first = first->next;
			box->next = first->next;
			first->next = box;
		}
	}
	return (box);
}

void	create_meta_box(t_map **map, t_meta *m, char c)
{
	t_box	*box;
	int		up;

	up = 1;
	box = NULL;
	if (c == (*map)->blank)
	{
		if (m->line > 0)
		{
			if ((*map)->tab[m->col][m->line - 1])
				up = (*map)->tab[m->col][m->line - 1]->nb_up + 1;
			else
				up = 1;
		}
		box = insert_sort_box(map, do_box(m->col, m->line, m->left, up));
	}
	if (m->line > 0 && m->line < (*map)->height && m->col < (*map)->width)
		(*map)->tab[m->col][m->line] = box;
	m->col++;
	m->left++;
}
