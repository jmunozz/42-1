/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 14:57:53 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/11 20:53:47 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr_abs(long int nb)
{
	if ((nb / 10) != 0)
		ft_putnbr_abs(nb / 10);
	ft_putchar((nb % 10) + '0');
}

void	ft_putnbr(int nb)
{
	long int nbl;

	nbl = nb;
	if (nbl < 0)
	{
		nbl *= -1;
		ft_putchar('-');
	}
	ft_putnbr_abs(nbl);
}
