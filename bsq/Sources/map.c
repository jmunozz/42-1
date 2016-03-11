/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 17:03:18 by jubarbie          #+#    #+#             */
/*   Updated: 2016/02/18 11:45:47 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		map_init(t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (*map == NULL)
		return (-1);
	(*map)->first = NULL;
	(*map)->tab = NULL;
	(*map)->meta = NULL;
	(*map)->width = 0;
	(*map)->height = 0;
	(*map)->blank = 0;
	(*map)->wall = 0;
	(*map)->fill = 0;
	(*map)->meta = malloc(sizeof(t_meta));
	(*map)->meta->line = 0;
	(*map)->meta->col = 0;
	(*map)->meta->left = 1;
	(*map)->meta->pos = 0;
	return (0);
}

int		get_map_infos(t_map **map, char *buf)
{
	char	*temp;
	int		i;

	temp = buf;
	i = 0;
	while (*buf && *buf != '\n')
	{
		buf++;
		i++;
	}
	if (!*buf)
		return (-1);
	(*map)->fill = *--buf;
	(*map)->wall = *--buf;
	(*map)->blank = *--buf;
	*buf = '\0';
	(*map)->height = ft_atoi(temp);
	(*map)->meta->pos = ++i;
	if ((*map)->blank == (*map)->wall)
		return (-1);
	return (0);
}

int		new_line(t_map **map, t_meta *meta, char c)
{
	if (c == '\n')
	{
		if (meta->line == 0)
		{
			(*map)->width = meta->col - 1;
			tab_init(map);
		}
		else if ((*map)->width != meta->col - 1)
			return (-1);
		meta->col = 0;
		meta->line++;
		meta->left = 1;
	}
	if (c == (*map)->wall)
		meta->left = 1;
	return (0);
}

int		fill_map(t_map **map, int fd)
{
	char	buf[BUF + 1];
	int		ret;
	int		i;

	ret = BUF;
	while (ret == BUF)
	{
		i = 0;
		ret = read(fd, buf, BUF);
		buf[ret] = '\0';
		while (buf[i])
		{
			if (buf[i] != (*map)->blank && buf[i] != (*map)->wall &&
					buf[i] != '\n')
				return (-1);
			create_meta_box(map, (*map)->meta, buf[i]);
			if (new_line(map, (*map)->meta, buf[i]) == -1)
				return (-1);
			i++;
		}
	}
	if ((*map)->meta->line != (*map)->height)
		return (-1);
	return (0);
}

int		create_map(t_map **map, char *file_name, int fd)
{
	char	buf[15];
	char	c[1];
	int		i;

	if (map_init(map) == -1)
		return (-1);
	if (fd != 0)
		fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	else
	{
		i = -1;
		while (++i < 15 && *c != '\n' && read(fd, c, 1) == 1)
			buf[i] = *c;
		if (i < 5)
			return (-1);
		buf[i] = '\0';
		if (get_map_infos(map, buf) == -1)
			return (-1);
		if (fill_map(map, fd) == -1)
			return (-1);
		close(fd);
	}
	return (0);
}
