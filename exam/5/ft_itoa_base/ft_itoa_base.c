/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:44:12 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/08 17:41:07 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char b[17] = "0123456789ABCDEF";

int	ft_nblen(int nb, int base)
{
	int ret;

	ret = 1;
	if (nb / base)
		ret += ft_nblen(nb / base, base);
	return (ret);
}

void ft_doitoa_base(long int value, int base, char *str)
{
	if (value / base)
		ft_doitoa_base(value / base, base, str - 1);
	value %= base;
	*str = b[value];
}

char *ft_itoa_base(int value, int base)
{
	char *str;
	int nblen;
	long int nbr;

	if (base >= 2)
	{
		nbr = (long int)value;
		nblen = ft_nblen(value, base);
		if (value < 0 && base == 10)
			nblen++;
		str = (char *)malloc(sizeof(char) * nblen + 1);
		if (!str)
			return (NULL);
		str[0] = '-';
		nbr *= (nbr < 0) ? -1 : 1;
		str[nblen] = '\0';
		ft_doitoa_base(nbr, base, &str[nblen - 1]);
		return (str);
	}
	return (NULL);
}
