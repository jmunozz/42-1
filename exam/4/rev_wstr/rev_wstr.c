/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 10:54:13 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/11 19:47:46 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev_wstr(char *str, int i)
{
	char	*ptr;

	ptr = str;
	while (*ptr && *ptr != ' ')
		ptr++;
	if (*ptr && *ptr == ' ')
		rev_wstr(++ptr, i + 1);
	while (*str && *str != ' ')
		write(1, str++, 1);
	if (i != 0)
		write(1, " ", 1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1], 0);
	write (1, "\n", 1);
	return (0);
}
