/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 11:22:35 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/08 13:06:27 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putnbr(int i)
{
	char c;
	
	if (i >= 0 && i <= 9)
		c = 48 + i;
	else if (i >= 10 && i <= 15)
		c = 87 + i;
	write(1, &c, 1);
}

void	ft_display(int nb)
{
	int i;

	i = 0;
	if (nb / 16 != 0)
		ft_display(nb / 16);
	ft_putnbr(nb % 16);
}

void	print_memory(int *addr, size_t size)
{
	unsigned int i;
	unsigned int	j;

	i = 0;
	while (i < size)
	{
		if (addr[i] < 16)
			write(1, "0", 1);
		ft_display((int)addr[i]);
		write(1, "00 0000 ", 8);
		if ((i + 1) % 4 == 0)
			write(1, "................\n", 17);
		else if (i + 1 == size)
		{
			j = i;
			while (++j % 4 != 0)
				write(1, "          ", 10);
			write(1, "................", (4 * ((i + 1) % 4)));
			write(1, "\n", 1);
		}
		i++;
	}
}
