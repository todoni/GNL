/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 10:56:52 by sohan             #+#    #+#             */
/*   Updated: 2021/06/12 11:10:29 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	char *str = "1\n\n\n\n2";
	t_list *result = gnl_split(str, '\n');
	char *joined = "";
	t_list *curr = result;

	while (curr)
	{
		printf("%s\n", curr->content);
		curr = curr->next;
	}
	curr = result;
	while (curr)
	{
		joined = gnl_strjoin(joined, (const char*)(curr->content));
		curr = curr->next;
	}
	printf("joined :\n%s\n", joined);
}
