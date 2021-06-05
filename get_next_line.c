/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refactoring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:11:30 by sohan             #+#    #+#             */
/*   Updated: 2021/06/04 14:27:40 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	t_list		*node;
	t_list		*temp;
	char		*joined;
	char		*new_line;
	static char	*save;
	int			i;
	int			status;
	int			len;
	int			c;

	node = 0;
	joined = "";
	if (BUFFER_SIZE == 0 || BUFFER_SIZE == -1)
		return (-1);
	while (1)
	{
		new_line = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if ((status = read(fd, new_line, BUFFER_SIZE)) == -1)
			return (-1);
		if (save == 0)
			save = new_line;
		else
		{
			len = ft_strlen(save);
			save = ft_strjoin(save, new_line);
		}
		i = 0;
		while (i < len + BUFFER_SIZE)
		{
			if (*(save + i) == '\n')
			{
				status = 1;
				break ;
			}
			i++;
		}
		temp = ft_lstnew((void*)ft_substr(save, 0, i));
		c = save[i];
		save = ft_substr(save, i + 1, len + BUFFER_SIZE);
		ft_lstadd_back(&node, temp);
		if ((status == 0 && *save == 0) || (status == 1 && c == '\n'))
			break;
	}
	while (node)
	{
		joined = ft_strjoin(joined, node->content);
		temp = node;
		node = node->next;
		ft_lstdelone(temp, &free);
	}
	*line = joined;
	free(new_line);
	return ((int)status);
}
