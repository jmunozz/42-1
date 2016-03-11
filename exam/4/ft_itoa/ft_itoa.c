/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 15:21:57 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/11 19:42:03 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_nblen(int nb)
{
	int i;

	i = (nb >= 0) ? 1 : 2;
	while (nb /= 10)
		i++;
	return (i);
}

void ft_doatoi(int nbr, char *str)
{
	if (nbr / 10)
		ft_doatoi(nbr / 10, str - 1);
	*str = '0' + nbr % 10;
}

char *ft_itoa(int nbr)
{
	int nblen;
	char *str;

	if (nbr == -2147483648)
		return ("-2147483648");
	nblen = ft_nblen(nbr);
	if (!(str = (char *)malloc(sizeof(char) * nblen + 1)))
		return (NULL);
	if (nbr < 0)
		str[0] = '-';
	nbr *= (nbr < 0) ? -1 : 1;
	str[nblen] = '\0';
	ft_doatoi(nbr, &str[--nblen]);
	return (str);
}
