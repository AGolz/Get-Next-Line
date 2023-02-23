/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:04:13 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/23 20:21:45 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd[3];
	char	*str;
	char	*str_1;
	char	*str_2;

	fd[0] = open("line_nl_no_nl", O_RDWR);
	fd[1] = open("41_with_nl", O_RDWR);
	fd[2] = open("42_with_nl", O_RDWR);
	str = get_next_line(fd[0]);
	str_1 = get_next_line(fd[1]);
	str_2 = get_next_line(fd[2]);
	while (str_1)
	{
		printf("gnl_1: %s\n", str_1);
		free(str_1);
		str_1 = get_next_line(fd[1]);
		while (str_2)
		{
			printf("gnl_2\n: %s", str_2);
			free(str_2);
			str_2 = get_next_line(fd[2]);
			while (str)
			{
				printf("gnl: %s", str);
				free(str);
				str = get_next_line(fd[0]);
			}
		}
	}
	free(str);
	free(str_1);
	free(str_2);
	system("leaks a.out");
	return (0);
}
