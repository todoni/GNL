/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:44:50 by sohan             #+#    #+#             */
/*   Updated: 2021/06/07 15:17:44 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int					get_next_line(int fd, char **line);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
static int			count_word(const char *str, char c);
static int			count_word_len(const char *str, char c);
static const char	*put_words(char **strs, const char *str, char c, int i);
static void			free_memory(char **strs, int i);
char				**ft_split(const char *str, char c);

#endif