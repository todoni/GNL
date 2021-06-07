/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:05:13 by sohan             #+#    #+#             */
/*   Updated: 2021/06/07 20:20:22 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_list	*save;
	t_list			*temp;
	char			*buffer;
	char			**blocks;
	int				val_read;
	int				i;

	buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == 0)
		return (-1);
	val_read = read(fd, buffer, BUFFER_SIZE);
	blocks = ft_split(buffer, '\n');
	free(buffer);
	i = 0;
	while (blocks[i])
	{
		ft_lstadd_back(&save, ft_lstnew((void*)blocks[i]));
		i++;
	}
	//if (save == 0)
	//	ft_lstadd_back(&save, ft_lstnew((void*)buffer));
	*line = save->content;
	if (save->next == 0 && val_read == 0)
		return (0);
	temp = save;
	free(save);
	save = temp->next;
	return (1);
}
