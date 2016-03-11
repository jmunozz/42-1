/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 10:05:58 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/08 10:10:02 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 2)
	{
		i = ft_strlen(av[1]);
		while (--i >= 0)
			write(1, &(av[1][i]), 1);
	}
	write(1, "\n", 1);
	return (0);
}
