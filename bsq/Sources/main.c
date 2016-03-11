/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 11:58:35 by jubarbie          #+#    #+#             */
/*   Updated: 2016/02/18 12:28:30 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int ac, char **av)
{
	t_map	*map;
	int		k;
	int		fd;

	map = NULL;
	k = 0;
	fd = 1;
	if (ac == 1)
	{
		fd = 0;
		k = -1;
	}
	while (++k < ac)
		if (create_map(&map, av[k], fd) == -1)
			ft_putstr(2, "map error\n");
		else
		{
			do_bsq(&map);
			map_print_stdout(&map);
			free_all(&map);
		}
	return (0);
}
