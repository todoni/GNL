/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:43:19 by sohan             #+#    #+#             */
/*   Updated: 2021/06/09 21:21:54 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			*buffer;
	char			**strs;
	static t_list	*save;
	t_list			*temp;
	ssize_t			val_read;
	int				i;


	*line = "";
	while (1)
	{
		i = 0;
		buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == 0)
			return (-1);
		val_read = read(fd, buffer, BUFFER_SIZE);
		buffer[val_read] = '\0';
		strs = ft_split(buffer, '\n');
		while (strs[i])
		{
			ft_lstadd_back(&save, ft_lstnew(ft_strdup(strs[i]), ft_strdup(buffer), i));
			i++;
		}
		free(strs);
		if (save == 0)
			ft_lstadd_back(&save, ft_lstnew("", "", 0));
		if ((ft_strchr(save->buffer, '\n') || ft_strchr(buffer, '\n')) && i > 1)
		{
			while (save->next->count == 0)
			{
				*line = ft_strjoin(*line, ft_strdup(save->content));
				temp = save;
				save = save->next;
				ft_lstdelone(temp, &free);
			}
			*line = ft_strjoin(*line, ft_strdup(save->content));
			temp = save;
			save = save->next;
			ft_lstdelone(temp, &free);
			return (1);
		}
		/*if (ft_strchr(buffer, '\n') && i <= 1)
		{	
			while (save)
			{
				*line = ft_strjoin(*line, ft_strdup(save->content));
				temp = save;
				save = save->next;
				ft_lstdelone(temp, &free);
			}
			return (1);
		}*/
		if (val_read == 0 && *(save->content) == 0)
		{	
			*line = ft_strdup(save->content);
			//ft_lstdelone(save, &free);
			return (0);
		}
	}
}
