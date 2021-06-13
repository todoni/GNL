#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

int		main()
{
	int		ret;
	char	*line;
	int		fd;
	int		count = 0;

	fd = open("alphabet", O_RDONLY);	
	
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s return : %d\n", line, ret);
		free(line);
		line = 0;
		count++;
	}
	printf("%s return : %d\n", line, ret);
	free(line);
	line = 0;
	close(fd);
	//while(1){;};
}
