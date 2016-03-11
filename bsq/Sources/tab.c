/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:43:35 by jmunoz            #+#    #+#             */
/*   Updated: 2016/02/18 11:40:28 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	tab_init(t_map **map)
{
	t_box	***tab;
	int		i;
	t_box	*first;

	i = -1;
	first = (*map)->first;
	tab = NULL;
	tab = malloc(sizeof(void*) * (*map)->width);
	while (++i < (*map)->width)
		tab[i] = malloc(sizeof(void*) * (*map)->height);
	i = -1;
	while (++i < (*map)->width)
	{
		if (!first || first->pos_x != i)
			tab[i][0] = NULL;
		else
		{
			tab[first->pos_x][0] = first;
			if (first->next)
				first = first->next;
		}
	}
	(*map)->tab = tab;
}
