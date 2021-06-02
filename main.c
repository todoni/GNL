#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

int		main()
{
	int		ret;
	char	*line;
	int		fd;

	fd = open("alphabet", O_RDONLY);	

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = 0;
	}
	printf("%s", line);
	free(line);
	line = 0;
}