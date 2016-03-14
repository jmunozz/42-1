/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:28:54 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/14 17:48:42 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*str;
	int 	i;

	fd = 0;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	/*i = get_next_line(fd, &str);
	printf("Size: %d\n%s\n", i, str);
	i = get_next_line(fd, &str);
	printf("Size: %d\n%s\n", i, str);*/
	while ((i = get_next_line(fd, &str)))
		printf("%s%d", str, i);
	printf("%s*%d", str, i);
	if (fd != 0)
		close(fd);
	return (0);
}
