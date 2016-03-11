/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 14:33:54 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/11 19:29:37 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		len;

	if (src)
	{
		len = ft_strlen(src);	
		if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ret[len] = '\0';
		while (len--)
			ret[len] = src[len];
		return (ret);
	}
	return (NULL);
}
