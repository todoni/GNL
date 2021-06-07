/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 13:56:20 by sohan             #+#    #+#             */
/*   Updated: 2021/06/07 10:51:59 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <malloc/malloc.h>
#include "get_next_line.h"

int	read_recursive(int fd)
{
	char	*buffer;
	int		read_value;
	int		return_value;
	buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == 0)
		return (-1);
	if (read_value == 0)
		return (0);
	read_value = read(fd, buffer, BUFFER_SIZE);
	return (return_value = read_recursive(fd));
}

int	main()
{
	int		fd;
	//int		fd2;
	//int		fd3;
	//int		index;
	int		i = 0;
	int		result;
	//int		bytes;
	//int		binary;*/
	char	*buf;
	//int		count = 1;
	//char	nulltest[] = "asdf\0dfdf\0asdf";
	//char	*test1 = "asdfg\nbdfsd\ndfasdfjisdff";
	if ((fd = open("alphabet", O_CREAT|O_RDWR, S_IRWXU)) == -1)
	{
		perror("[open] An error occurred!!!\n");
		exit (1);
	}
	/*if (write(fd, test1, 20) == -1)
	{
		perror("[write] An error occurred!!!\n");
		exit (1);
	}
	lseek(fd, 0, SEEK_SET);*/
	buf = malloc(1);
	result = read_recursive(fd);
	printf("%d\n", result);
	/*printf("size of buf is %zu after user memory allocation.\n", malloc_size(buf));
	if ((bytes = read(fd, buf, BUFFER_SIZE)) == -1)
	{
		perror("[read] An error occurred!!!\n");
		exit (1);
	}
	printf("size of buf is %zu after read().\n", malloc_size(buf));
	lseek(fd, 0, SEEK_SET);
	if ((fd2 = open("result", O_CREAT|O_RDWR|O_TRUNC, S_IRWXU)) == -1)
	{
		perror("[open] An error occurred!!!\n");
		exit (1);
	}
	if (write(fd2, buf, BUFFER_SIZE) == -1)
	{
		perror("[write] An error occurred!!!\n");
		exit (1);
	}
	lseek(fd2, 0, SEEK_SET);*/
	/*while (1)
	{
		result = get_next_line(fd, &buf);
		printf("[test.c line %d]:gnl returns %d.\nbuf is %s\n", i + 1, result, buf);
		if (result == 0 || result == -1)
			break;
		i++;
	}
	//printf("buf is \n%s\n", buf);
	index = read(fd2, buf, BUFFER_SIZE);
	if ((fd3 = open("get_next_line.h.gch", O_RDONLY)) == -1)
	{
		perror("[open] An error occurred!!!\n");
		exit (1);
	}
	if ((binary = read(fd3, buf, BUFFER_SIZE)) == -1)
	{
		perror("[read] An error occurred!!!\n");
		exit (1);
	}
	if (write(fd2, buf, BUFFER_SIZE) == -1)
	{
		perror("[write] An error occurred!!!\n");
		exit (1);
	}
	printf("read() read \n%d bytes from test1.\n%d wrote to the result.\n%d bytes from binary file.\n", bytes, index, binary);*/
	close(fd);
	//close(fd2);
	//close(fd3);
	free(buf);
	return (0);
}
