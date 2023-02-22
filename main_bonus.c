/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:26:23 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/22 19:36:22 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int main(void)
{
	int fd[4];
	fd[0] = open("line_nl_no_nl", O_RDWR);
	printf("gnl: %s",get_next_line(fd[0]));
	printf("gnl: %s",get_next_line(fd[0]));
	printf("gnl: %s",get_next_line(fd[0]));
	printf("gnl: %s",get_next_line(fd[0]));
	printf("gnl: %s",get_next_line(fd[0]));
	printf("gnl: %s",get_next_line(fd[0]));
	printf("gnl: %s",get_next_line(fd[0]));
	printf("gnl: %s",get_next_line(fd[0]));
	printf("gnl: %s\n",get_next_line(fd[0]));
	printf("gnl: %s\n",get_next_line(fd[0]));
	return (0);
}
