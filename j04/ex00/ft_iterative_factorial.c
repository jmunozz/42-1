/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 10:47:34 by jubarbie          #+#    #+#             */
/*   Updated: 2015/10/27 10:29:59 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int res;

	i = 1;
	res = 1;
	if ((nb < 0) || (nb >= 13))
		return (0);
	else if (nb == 0)
		return (1);
	while (i <= nb)
		res *= i++;
	return (res);
}
