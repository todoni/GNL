/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:56:20 by sohan             #+#    #+#             */
/*   Updated: 2021/05/29 21:46:56 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
int	main()
{
	int		fd;
	int		index;
	int		i = 0;
	int		result;
	char	*buf;
	//char	nulltest[] = "asdf\0dfdf\0asdf";
	char	*test1 = "asdfg\nbdfsd\ndf";
	if ((fd = open("gnltest", O_CREAT|O_RDWR|O_TRUNC, S_IRWXU)) == -1)
	{
		perror("[open] An error occurred!!!\n");
		exit (1);
	}
	if (write(fd, test1, 15) == -1)
	{
		perror("[write] An error occurred!!!\n");
		exit (1);
	}
	lseek(fd, 0, SEEK_SET);
	buf = calloc(15, sizeof(char));
	/*if (read(fd, buf, BUFFER_SIZE) == -1)
	{
		perror("[read] An error occurred!!!\n");
		exit (1);
	}*/
	printf("[test.c]:line45 pass\n");
	while (1)
	{
		result = get_next_line(fd, &buf);
		printf("[line %d] gnl returns %d.\n", i + 1, result);
		if (result == 0 || result == -1)
			break;
		i++;
	}
	index = lseek(fd, 0, SEEK_END);
	printf("program end at line %d : %s, buffer has %d bytes.", i + 1, buf, index);
	close(fd);
	free(buf);
	return (0);
}
