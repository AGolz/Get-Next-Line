/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:08:06 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/22 19:36:30 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int fd;
	fd = open("line_nl_no_nl", O_RDWR);
	printf("gnl: %s",get_next_line(fd));
	printf("gnl: %s",get_next_line(fd));
	printf("gnl: %s",get_next_line(fd));
	printf("gnl: %s",get_next_line(fd));
	printf("gnl: %s",get_next_line(fd));
	printf("gnl: %s",get_next_line(fd));
	printf("gnl: %s",get_next_line(fd));
	printf("gnl: %s",get_next_line(fd));
	printf("gnl: %s\n",get_next_line(fd));
	printf("gnl: %s\n",get_next_line(fd));
	return (0);
}
