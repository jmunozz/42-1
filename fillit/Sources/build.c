/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:42:45 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/11 16:34:20 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int g_valid[19][4] = {{15, 0, 0, 0}, {7, 4, 0, 0}, {7, 2, 0, 0}, {7, 1, 0, 0},
	{3, 3, 0, 0}, {6, 3, 0, 0}, {3, 2, 2, 0}, {3, 1, 1, 0}, {3, 6, 0, 0},
	{4, 7, 0, 0}, {2, 3, 2, 0}, {2, 3, 1, 0}, {2, 2, 3, 0}, {1, 1, 1, 1},
	{2, 7, 0, 0}, {1, 3, 2, 0}, {1, 3, 1, 0}, {1, 1, 3, 0}, {1, 7, 0, 0}};

static unsigned int	treat_line(char *buf)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (buf[i] != '.' && buf[i] != '#')
			map_error();
	if (buf[i] != '\n')
		map_error();
	else
		buf[i] = '\0';
	return (ft_atoi(ft_convert_base(ft_strrev(buf), BASE_TETRI, BASE_DEC)));
}

void				map_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void				verif_tetri(t_meta *meta)
{
	int	i;
	int	j;
	int	k;
	int	cmp;

	i = -1;
	while (++i < NB_TETRI)
	{
		j = -1;
		while (++j < 19)
		{
			k = -1;
			cmp = 0;
			while (++k < 4)
				cmp += (TETRI[i][k] ^ g_valid[j][k]);
			if (cmp == 0)
				j = 19;
		}
		if (cmp != 0)
			map_error();
	}
}

int					open_file(char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		map_error();
	return (fd);
}

void				file_to_tab(int fd, t_meta *meta)
{
	char	buf[5];
	int		i;
	int		j;
	int		ret;

	ret = 1;
	while (ret)
	{
		i = NB_TETRI - 1;
		j = -1;
		while (++j < 4)
		{
			ret = read(fd, buf, 5);
			TETRI[i][j] = treat_line(buf);
		}
		stick_tetri_up_right(TETRI[i]);
		ret = read(fd, buf, 1);
		if (ret && *buf != '\n')
			map_error();
		if (ret)
			TETRI = add_tetri_tab(TETRI, NB_TETRI++);
	}
	if (NB_TETRI > 26)
		map_error();
	close(fd);
}
