/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:03:35 by jmunoz            #+#    #+#             */
/*   Updated: 2016/02/18 11:56:39 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_all(t_map **map)
{
	int	i;

	i = -1;
	free((*map)->meta);
	while (++i < (*map)->width)
		free((*map)->tab[i]);
	free((*map)->tab);
	box_clear(map);
	free(*map);
	(*map) = NULL;
}

void	print_square(t_map **map, int fd)
{
	char	*buf;
	int		j;

	j = -1;
	while (++j < (*map)->meta->left)
		write(fd, &((*map)->fill), 1);
	buf = malloc(sizeof(char) * (*map)->width - (*map)->meta->left + 1);
	read(fd, buf, (*map)->width - (*map)->meta->left + 1);
	free(buf);
}

int		map_print_file(t_map **map, char *file_name)
{
	int		fd;
	int		pos;
	char	*buf;
	t_meta	*m;

	fd = open(file_name, O_RDWR);
	m = (*map)->meta;
	if (fd == -1)
		return (-1);
	else
	{
		pos = m->pos + ((*map)->width * m->line + m->col);
		buf = malloc(sizeof(char) * pos);
		read(fd, buf, pos);
		free(buf);
		pos = -1;
		while (++pos < m->left)
			print_square(map, fd);
	}
	close(fd);
	free_all(map);
	return (0);
}

int		map_print_stdout(t_map **map)
{
	t_box	***tab;
	int		i;
	int		j;
	t_meta	*m;

	tab = (*map)->tab;
	m = (*map)->meta;
	j = -1;
	while (++j < (*map)->height)
	{
		i = -1;
		while (++i < (*map)->width)
			if (tab[i][j])
			{
				if (i >= m->col && i < m->col + m->left &&
					j >= m->line && j < m->line + m->left)
					write(1, &((*map)->fill), 1);
				else
					write(1, &((*map)->blank), 1);
			}
			else
				write(1, &((*map)->wall), 1);
		write(1, "\n", 1);
	}
	return (0);
}
