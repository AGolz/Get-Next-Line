/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:08:06 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/23 14:49:44 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("line_nl_no_nl", O_RDWR);
	str = get_next_line(fd);
	while (str)
	{
		printf("gnlw: %s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	system("leaks a.out");
	return (0);
}
