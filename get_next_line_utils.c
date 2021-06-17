/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:43:48 by sohan             #+#    #+#             */
/*   Updated: 2021/06/17 12:24:16 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*move;

	move = *lst;
	if (*lst)
	{
		while (move->next)
			move = move->next;
		move->next = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstnew(void *content, size_t len, char newline)
{
	t_list	*lstnew;

	lstnew = (t_list*)malloc(1 * sizeof(t_list));
	if (lstnew == 0)
		return (0);
	lstnew->content = content;
	lstnew->len = len;
	lstnew->newline = newline;
	lstnew->next = 0;
	return (lstnew);
}

void	free_all_nodes(t_list **lst)
{
	while (*lst)
		free_one_and_next(lst);
}

int		ft_strchr(const char *s, int c)
{
	if (c == 0)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

char	*concatenate_nodes(t_list **save, char *joined)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*save && (*save)->newline != '\n')
	{
		while (j < (*save)->len)
		{
			*(joined + i) = *((char*)((*save)->content) + j);
			i++;
			j++;
		}
		free_one_and_next(save);
		j = 0;
	}
	while (*save && j < (*save)->len)
	{
		*(joined + i) = *((char*)((*save)->content) + j);
		i++;
		j++;
	}
	joined[i] = '\0';
	return (joined);
}
