/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:43:48 by sohan             #+#    #+#             */
/*   Updated: 2021/06/09 20:48:07 by sohan            ###   ########.fr       */
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

t_list	*ft_lstnew(char *content, char *buffer, int count)
{
	t_list	*lstnew;

	lstnew = (t_list*)malloc(1 * sizeof(t_list));
	if (lstnew == 0)
		return (0);
	lstnew->content = content;
	lstnew->buffer = buffer;
	lstnew->count = count;
	lstnew->next = 0;
	return (lstnew);
}

static int			count_word(const char *str, char c)
{
	int	word_count;

	word_count = 0;
	while (*str)
	{
		while (*str != c && *str)
			str++;
		if (*(str - 1) != c)
		{
			word_count++;
		}
		if (*str == '\0')
			break ;
		str++;
	}
	return (word_count);
}

static int			count_word_len(const char *str, char c)
{
	int word_len;

	word_len = 0;
	while (*str != c && *str)
	{
		str++;
		word_len++;
	}
	return (word_len);
}

static const char	*put_words(char **strs, const char *str, char c, int i)
{
	int j;

	j = 0;
	while (*str != c && *str)
	{
		strs[i][j] = *str;
		j++;
		str++;
	}
	strs[i][j] = '\0';
	while (*str == c)
		str++;
	return (str);
}
void				free_memory(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = 0;
		i++;
	}
	free(strs);
}

char				**ft_split(const char *str, char c)
{
	char	**strs;
	int		i;
	int		num_word;

	strs = 0;
	i = 0;
	while (*str == c && *str)
		str++;
	num_word = count_word(str, c);
	strs = (char **)malloc((num_word + 1) * sizeof(char *));
	if (strs == 0)
		return (0);
	while (i < num_word)
	{
		strs[i] = (char *)malloc((count_word_len(str, c) + 1) * sizeof(char));
		if (strs[i] == 0)
		{
			free_memory(strs);
			return (0);
		}
		str = put_words(strs, str, c, i);
		i++;
	}
	strs[i] = 0;
	return (strs);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr_copy;

	len = 0;
	len = ft_strlen(s1);
	ptr_copy = (char *)malloc(len * sizeof(char) + 1);
	if (ptr_copy == 0)
		return (0);
	while (*s1)
	{
		*ptr_copy = *s1;
		s1++;
		ptr_copy++;
	}
	*ptr_copy = '\0';
	ptr_copy -= len;
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
	origin[i]= '\0';
	return (origin);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;
	size_t	len_joined;

	len_joined = ft_strlen(s1) + ft_strlen(s2);
	str_joined = (char *)malloc((len_joined + 1) * sizeof(char));
	if (str_joined == 0)
		return (0);
	str_joined = append_str(str_joined, s1);
	str_joined += ft_strlen(s1);
	str_joined = append_str(str_joined, s2);
	str_joined -= ft_strlen(s1);
	return (str_joined);
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
