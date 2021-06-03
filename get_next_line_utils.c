/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:35:24 by sohan             #+#    #+#             */
/*   Updated: 2021/06/03 19:51:17 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (len + start > ft_strlen(s))
		len = ft_strlen(s + start);
	substr = (char*)malloc(len + 1);
	if (substr == 0)
		return (0);
	while (start < ft_strlen(s) && i < len)
	{
		*(substr + i) = *(s + start + i);
		i++;
		if (*(s + start + i) == '\0')
			break ;
	}
	*(substr + i) = '\0';
	return (substr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	memory = malloc(count * size);
	if (memory == 0)
		return (0);
	return (memory = ft_memset(memory, 0, count * size));
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		*((unsigned char*)b + i) = c;
		i++;
	}
	return (b);
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*move;

	move = *lst;
	if (*lst)
	{
		move = ft_lstlast(*lst);
		move->next = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = (t_list*)malloc(sizeof(t_list));
	if (lstnew == 0)
		return (0);
	lstnew->content = content;
	lstnew->next = 0;
	return (lstnew);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (lst == 0)
		return (0);
	while (lst->next)
		lst = lst->next;
	last = lst;
	return (last);
}

char	*append_str(char *origin, const char *str)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = ft_strlen(str);
	while (i < index)
	{
		origin[i] = str[i];
		i++;
	}
	return (origin);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;
	size_t	len_joined;

	len_joined = ft_strlen(s1) + ft_strlen(s2);
	str_joined = (char *)ft_calloc((len_joined + 1), sizeof(char));
	if (str_joined == 0)
		return (0);
	str_joined = append_str(str_joined, s1);
	str_joined += ft_strlen(s1);
	str_joined = append_str(str_joined, s2);
	str_joined -= ft_strlen(s1);
	return (str_joined);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = ft_lstnew((*lst)->next);
		ft_lstdelone(*lst, del);
		*lst = temp->content;
		free(temp);
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
