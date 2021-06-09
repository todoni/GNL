/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:44:50 by sohan             #+#    #+#             */
/*   Updated: 2021/06/09 20:50:09 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	char			*content;
	char			*buffer;
	ssize_t			readval;
	int				count;
	struct s_list	*next;
}				t_list;

int					get_next_line(int fd, char **line);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(char *content, char *buffer, int count);
static int			count_word(const char *str, char c);
static int			count_word_len(const char *str, char c);
static const char	*put_words(char **strs, const char *str, char c, int i);
void				free_memory(char **strs);
char				**ft_split(const char *str, char c);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
char				*append_str(char *origin, const char *s);
int					ft_strchr(const char *s, int c);

#endif
