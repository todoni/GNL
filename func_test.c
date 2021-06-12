#include <stdio.h>
#include "get_next_line.h"

t_list    *split(const char *s, char sep)
{
    t_list  	*node;
	size_t		i;

    node = 0;
	i = 0;
    while (*s)
	{
		while (s[i] != sep && s[i])
        	i++;
		ft_lstadd_back(&node, ft_lstnew(ft_strndup(s, i)));
		s += i;
		s++;
		i = 0;
	}
	return (node);
}

int	main()
{
	char	*str = "asdf\nzxcv\nqwer\n";
	t_list	*result = split(str, '\n');

	while (result)
	{
		printf("%s\n", result->content);
		result = result->next;
	}
}
