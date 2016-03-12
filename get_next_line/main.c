#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	fd;
	char	*str;

	fd = 0;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	i = get_next_line(fd, &str);
	printf("Size: %d\n%s\n", i, str);
	if (fd != 0)
		close(fd);
	return (0);
}
