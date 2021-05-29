/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:22:23 by sohan             #+#    #+#             */
/*   Updated: 2021/05/29 21:38:34 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int	get_next_line(int fd, char **line)
{
	int				len;
	static int		i;
	char			*buffer;

	i = 0;
	buffer = calloc(BUFFER_SIZE, sizeof(char));
	if ((len = read(fd, (void*)buffer, BUFFER_SIZE)) == -1)
		return (-1);
	//printf("%d bytes read.\n", len);
	while (i < len)
	{
		//printf("[gnl]:line28 passes.\n");
		//printf("line 29:%c, %c\n", **(line + i), *(buffer + i));
		if (*(buffer + i) == '\n')
		{
			len = 1;
			break;
		}
		*(*line + i) = *(buffer + i);
		//printf("line 31:%c, %c\n", **(line + i), *(buffer + i));
		//printf("[gnl]:line32 passes.\n[%d]line is %s.\nbuffer is\n%s.\n", i, *line, buffer);
		i++;
	}
	//printf("get_next_line succesfully end. Bye bye!\n");
	return (len);
}
