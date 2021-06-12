/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:44:50 by sohan             #+#    #+#             */
/*   Updated: 2021/06/12 15:57:08 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			len;
	struct s_list	*next;
}				t_list;

int					get_next_line(int fd, char **line);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content, size_t len);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
char				*ft_strndup(const char *s1, size_t n);
size_t				ft_strlen(const char *s);
int					ft_strchr(const char *s, int c);
t_list				*gnl_split(const char *str, char sep);
char				*gnl_strjoin(t_list **save, ssize_t size);

#endif
