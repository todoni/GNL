/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:43:48 by sohan             #+#    #+#             */
/*   Updated: 2021/06/17 11:58:21 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_one_and_next(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	free(temp->content);
	temp->content = 0;
	free(temp);
	temp = 0;
}

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

char	*ft_strndup(const char *s1, size_t n)
{
    size_t  i;
	char	*ptr_copy;

	i = 0;
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

t_list	*gnl_split(const char *str, char sep, ssize_t *success)
{
	t_list	*node;
	t_list	*temp_node;
	char	*temp_str;
	size_t	i;

	node = 0;
	i = 0;
	while (*str)
	{
		while (str[i] != sep && str[i])
			i++;
		if ((temp_str = ft_strndup(str, i)) == 0 || \
				(temp_node = ft_lstnew(temp_str, i, str[i])) == 0)
		{
			free_all_nodes(&node);
			*success = -1;
			return (0);
		}
		ft_lstadd_back(&node, temp_node);
		str += i;
		if (*str == sep)
			str++;
		i = 0;
	}
	return (node);
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

char	*gnl_strjoin(t_list **save, ssize_t *success)
{
	size_t	len_joined;
	t_list	*curr;
	char	*joined;

	if (*success == -1)
		return (0);
	len_joined = 0;
	curr = *save;
	while (curr && curr->newline != '\n')
	{
		len_joined += curr->len;
		curr = curr->next;
	}
	if (curr)
		len_joined += curr->len;
	joined = (char*)malloc((len_joined + 1) * sizeof(char));
	if (joined == 0)
	{
		*success = -1;
		return (0);
	}
	joined = concatenate_nodes(save, joined);
	return (joined);
}
