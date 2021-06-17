/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:43:19 by sohan             #+#    #+#             */
/*   Updated: 2021/06/17 11:46:37 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static t_list	*save[OPEN_MAX];
	ssize_t			read_val;

	read_val = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	while (read_val)
	{
		if ((read_val = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[read_val] = '\0';
		ft_lstadd_back(&save[fd], gnl_split(buffer, '\n', &read_val));
		if (ft_strchr(buffer, '\n') == 1 || read_val == -1)
			break;
	}
	*line = gnl_strjoin(&save[fd], &read_val);
	if (save[fd] && save[fd]->newline == '\n' && read_val != -1)
	{
		free_one_and_next(&save[fd]);
		read_val = 1;
	}
	return (read_val);
}
