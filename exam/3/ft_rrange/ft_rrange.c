/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 10:26:50 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/08 10:50:15 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*ret;
	int	size;

	size = (end >= start) ? (end - start + 1) : (start - end + 1);
	ret = (int*)malloc(sizeof(int) * size);
	if (ret == NULL)
		return (NULL);
	while (--size >= 0)
		ret[size] = (end >= start) ? start++ : start--;
	return (ret);
}
