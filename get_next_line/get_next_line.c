#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int	ret;
	int	len;
	int	i;

	if (!(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	len = 0;
	**line = '\0';
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		i = 0;
		while (i < ret && buf[i] && buf[i] != '\n')
			i++;
		len += i;
		ft_strlcat(*line, buf, len + 1);
		if (!buf[len % ret] || buf[len % ret] == '\n' || ret != BUFF_SIZE)
			return (len);
	}
	return (len);
}
