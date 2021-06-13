/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:43:48 by sohan             #+#    #+#             */
/*   Updated: 2021/06/12 17:02:54 by sohan            ###   ########.fr       */
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

t_list	*ft_lstnew(void *content, size_t len)
{
	t_list	*lstnew;

	lstnew = (t_list*)malloc(1 * sizeof(t_list));
	if (lstnew == 0)
		return (0);
	lstnew->content = content;
	lstnew->len = len;
	lstnew->next = 0;
	return (lstnew);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
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

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
    size_t  i;
	char	*ptr_copy;

	len = 0;
	i = 0;
	len = ft_strlen(s1);
	if (n > len)
		n = len;
	ptr_copy = (char *)malloc((n + 1) * sizeof(char));
	if (ptr_copy == 0)
		return (0);
	while (s1[i] && i < n)
	{
		ptr_copy[i] = s1[i];
		i++;
	}
	ptr_copy[i] = '\0';
	return (ptr_copy);
}

t_list	*gnl_split(const char *str, char sep)
{
	t_list	*node;
	size_t	i;

	node = 0;
	i = 0;
	while (*str)
	{
		while (str[i] != sep && str[i])
			i++;
		ft_lstadd_back(&node, ft_lstnew(ft_strndup(str, i + 1), i));
		str += i;
		if (*str == sep)
			str++;
		i = 0;
	}
	return (node);
}

char	*gnl_strjoin(t_list **save, ssize_t size)
{
	//size_t	len_joined;
	t_list	*curr;
	char	*joined;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	curr = *save;
	while (curr && ft_strchr(curr->content, '\n') == 0)
	{
		curr = curr->next;
		count++;
	}
	if (curr)
		count++;
	joined = (char*)malloc(((size * count) + 1) * sizeof(char));
	if (joined == 0)
		return (0);
	while (count--)
	{
		while (j < (*save)->len && *((char*)((*save)->content) + j))
		{
			*(joined + i) = *((char*)((*save)->content) + j);
			i++;
			j++;
		}
		curr = *save;
		*save = (*save)->next;
		ft_lstdelone(curr, &free);
		j = 0;
	}
	joined[i] = '\0';
	return (joined);
}
