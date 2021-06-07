/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:43:48 by sohan             #+#    #+#             */
/*   Updated: 2021/06/07 15:17:06 by sohan            ###   ########.fr       */
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
static void			free_memory(char **strs, int i)
{
	int	index;

	index = 0;
	while (index <= i)
	{
		free(strs[index]);
		strs[index] = 0;
		index++;
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
			free_memory(strs, i);
			return (0);
		}
		str = put_words(strs, str, c, i);
		i++;
	}
	strs[i] = 0;
	return (strs);
}
