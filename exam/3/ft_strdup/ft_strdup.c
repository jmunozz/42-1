/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 14:33:54 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/08 14:46:04 by jubarbie         ###   ########.fr       */
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
	int		i;

	if (src)
	{
		len = ft_strlen(src);	
		ret = (char *)malloc(sizeof(char) * len + 1);
		if (ret == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			ret[i] = src[i];
			i++;
		}
		ret[len] = '\0';
		return (ret);
	}
	return (NULL);
}
