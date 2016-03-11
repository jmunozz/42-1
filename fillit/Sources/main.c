/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:35:33 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/11 14:37:38 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_meta	*meta;

	if (ac == 2)
	{
		meta = init_meta();
		file_to_tab(open_file(av[1]), meta);
		verif_tetri(meta);
		fillit(meta);
		free_meta(meta);
	}
	else
		ft_putendl("usage: ./fillit source_file");
	return (0);
}
