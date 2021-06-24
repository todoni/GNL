/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:53:09 by sohan             #+#    #+#             */
/*   Updated: 2021/06/18 17:55:10 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	fd = open("5.txt", O_RDONLY);

	//&line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s return3 : %d\n", line, ret);
		free(line);
		line = 0;
		count++;
	}
	printf("%s return3 : %d\n", line, ret);
	free(line);
	line = 0;
	close(fd);
	//while(1){;};
}
