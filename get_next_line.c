/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:43:19 by sohan             #+#    #+#             */
/*   Updated: 2021/06/12 17:05:34 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	static t_list	*save;
	ssize_t			read_val;

	*line = "";
	read_val = 1;
	while (read_val)
	{
		buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == 0)
			return (-1);
		read_val = read(fd, buffer, BUFFER_SIZE);
		buffer[read_val] = '\0';
		ft_lstadd_back(&save, gnl_split(buffer, '\n'));
		if (ft_strchr(buffer, '\n') == 1)
			break;
	}
	*line = gnl_strjoin(&save, BUFFER_SIZE);
	if (save || **line)
		read_val = 1;
	return (read_val);
}
