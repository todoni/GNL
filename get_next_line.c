/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:11:30 by sohan             #+#    #+#             */
/*   Updated: 2021/05/31 19:45:36 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*save;
	int			i;
	int			index;
	int			status;

	i = 0;
	index = 0;
	if ((status = read(fd, *line, BUFFER_SIZE)) == -1)
		return (-1);
	if (status > 0)
		save = *line;
	while (i < status)
	{
		if (*(save + i) == '\n')
		{
			status = 1;
			break;
		}
		i++;
	}
	while (index < i)
	{
		*(*line + index) = *(save + index);
		index++;
	}
	save += index + 1;
	return (status);
}
