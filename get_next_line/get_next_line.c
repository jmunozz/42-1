/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:19:47 by jubarbie          #+#    #+#             */
/*   Updated: 2016/03/14 17:54:36 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFF_LIM + 1];
	static int	i = -1;
	int			ret;

	if (!(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	**line = '\0';
	if (i != -1)
	{
		i++;
		while (i < BUFF_LIM && buf[i] == '\n')
			i++;
		*line = ft_strjoin(*line, &buf[i]);
	}
	while ((ret = read(fd, buf, BUFF_LIM)))
	{
		i = 0;
		buf[ret] = '\0';
		while (i < ret && buf[i] && buf[i] != '\n')
			i++;
		buf[i] = '\0';
		*line = ft_strjoin(*line, buf);
		if (i != ret || buf[i] == '\n' || ret != BUFF_LIM)
			return (1);
	}
	return (0);
}
