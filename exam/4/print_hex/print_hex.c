/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 14:46:30 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/08 15:21:24 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *nb)
{
	int	ret;
	int len;
	int i;

	ret = 0;
	i = 1;
	len = ft_strlen(nb);
	while (--len >= 0)
	{
		ret += (nb[len] - 48) * i;
		i *= 10;
	}
	return (ret);
}

void	print_hex(int nb)
{
	char c;

	if (nb / 16)
		print_hex(nb / 16);
	nb %= 16;
	if (nb >= 0 && nb <= 9)
		c = nb + '0';
	else if (nb >= 10 && nb <= 15)
		c = nb + 87;
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write (1, "\n", 1);
	return (0);
}
