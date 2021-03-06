/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:44:50 by sohan             #+#    #+#             */
/*   Updated: 2021/06/17 12:33:12 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

typedef struct	s_list
{
	void			*content;
	size_t			len;
	char			newline;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstnew(void *content, size_t len, char newline);
void			free_one_and_next(t_list **lst);
void			free_all_nodes(t_list **lst);
char			*ft_strndup(const char *s1, size_t n);
int				ft_strchr(const char *s, int c);
t_list			*gnl_split(const char *str, char sep, ssize_t *success);
char			*gnl_strjoin(t_list **save, ssize_t *success);
char			*concatenate_nodes(t_list **save, char *joined);

#endif
