/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:11:30 by sohan             #+#    #+#             */
/*   Updated: 2021/05/31 21:31:06 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	t_list		*node;
	t_list		*temp;
	static int	bytes;
	int			i;
	int			status;

	node = 0;
	while ((status = read(fd, *line, BUFFER_SIZE)))
	{
		while (i < status)
		{
			if (*(*line + i) == '\n')
			{
				status = 1;
				break;
			}
			i++;
		}
		temp = ft_lstnew((void*)ft_substr(*line, 0, i));
		ft_lstadd_back(&node, temp);
		i = 0;
	}
	while (node)
	{
		*line = ft_strjoin(*line, node->content);
		node = node->next;
	}
	return (status);
}
