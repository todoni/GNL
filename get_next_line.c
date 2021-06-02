/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:11:30 by sohan             #+#    #+#             */
/*   Updated: 2021/06/02 19:45:07 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	t_list		*node;
	t_list		*temp;
	char		*joined;
	static char	*save;
	int			i;
	int			status;

	node = 0;
	temp = 0;
	joined = "";
	if ((*line = malloc(1)) == 0)
		return (-1);
	while (1)
	{
		if ((status = read(fd, *line, BUFFER_SIZE)) == -1)
			return (-1);
		if (status == 0 && *save != 0)
		{
			*line = save;
			status = BUFFER_SIZE;
		}
		i = 0;
		while (i < status)
		{
			if (*(*line + i) == '\n')
			{
				status = 1;
				break;
			}
			i++;
		}
		if (*line != 0)
		{
			temp = ft_lstnew(ft_substr((const char*)*line, 0, i));
			save = ft_substr(*line, i + 1, BUFFER_SIZE);
		}
		if (status == 0 && *save == 0)
			return (0);
		ft_lstadd_back(&node, temp);
		if (status == 1)
			break;
	}
	while (node)
	{
		joined = ft_strjoin(joined, node->content);
		node = node->next;
	}
	*line = joined;
	return ((int)status);
}
