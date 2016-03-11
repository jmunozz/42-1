/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 11:59:38 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/09 12:35:18 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_words(char *str)
{
	int ret;

	ret = 0;
	if (*str && *str != ' ' && *str != '\t' && *str != '\n')
		ret++;
	while (*str++)
		if (*str && *str != ' ' && *str != '\t' && *str != '\n' &&
			(*(str - 1) == ' ' || *(str - 1) == '\t' || *(str - 1) == '\n'))
			ret++;
	return (ret);
}

int		ft_wlen(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}

char	**ft_split(char *str)
{
	char 	**tab;
	int		i;
	int		j;
	int		wlen;

	tab = (char **)malloc(sizeof(char *) * ft_count_words(str));
	i = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;
		if (*str)
		{
			wlen = ft_wlen(str);
			tab[i] = malloc(sizeof(char) * wlen + 1);
			j = 0;
			while (wlen-- > 0)
				tab[i][j++] = *str++;
			tab[i++][j] = '\0';
		}
	}
	return (tab);
}
