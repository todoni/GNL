/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refactoring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:40:37 by sohan             #+#    #+#             */
/*   Updated: 2021/06/05 11:55:36 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_next_line(int fd, char **line)
{
	t_list		*node;
	t_list		*temp;
	static char	*save;
	int			i;
	int			len;
	int			value_read;
	char		*new_line;

	i = 0;
	if ((value_read = read(fd, new_line, BUFFER_SIZE)) == -1)
		return (-1);
	if (save == 0)
		save = new_line;
	else
	{
		len = ft_strlen(save);
		save = ft_strjoin(save, new_line);
	}
	while (*(save + i) != '\n' && i < len + BUFFER_SIZE)
		i++;
	temp = ft_lstnew((void*)ft_substr(save, 0, i));
	node = ft_lstadd_back(&node, temp);
	if (*(save + i) == '\n')
		return (1);
	save = ft_substr(save, i + 1, len + BUFFER_SIZE);
	if (value_read == 0 && *save = 0)
		break;

}
