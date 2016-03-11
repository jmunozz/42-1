/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 18:27:13 by jubarbie          #+#    #+#             */
/*   Updated: 2015/11/04 17:49:29 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cast_nbr(char *str)
{
	int res;

	res = 0;
	while ((*str >= '0') && (*str <= '9'))
		res = res * 10 + (*str++ - 48);
	return (res);
}

int	ft_atoi(char *str)
{
	int i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t'))
		i++;
	if ((str[i] >= '0') && (str[i] <= '9'))
		return (ft_cast_nbr(&str[i]));
	else if (str[i] == '+')
		return (ft_cast_nbr(&str[i + 1]));
	else if (str[i] == '-')
		return (ft_cast_nbr(&str[i + 1]) * -1);
	else
		return (0);
}
