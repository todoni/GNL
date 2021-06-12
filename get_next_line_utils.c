/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:43:48 by sohan             #+#    #+#             */
/*   Updated: 2021/06/08 18:34:44 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	lstnew = (t_list*)malloc(1 * sizeof(t_list));
	if (lstnew == 0)
		return (0);
	lstnew->content = content;
	lstnew->next = 0;
	return (lstnew);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
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

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
    size_t  i;
	char	*ptr_copy;

	len = 0;
	len = ft_strlen(s1);
    i = 0;
	if (n > len)
        len = n;
	ptr_copy = (char *)malloc(len * sizeof(char) + 1);
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
