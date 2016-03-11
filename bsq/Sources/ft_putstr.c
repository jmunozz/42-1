/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 21:07:54 by jubarbie          #+#    #+#             */
/*   Updated: 2016/02/13 16:12:42 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(int fd, char *str)
{
	int n;

	n = 0;
	while (str[n])
	{
		ft_putchar(fd, str[n]);
		n++;
	}
}
