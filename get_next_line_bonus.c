/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:02:04 by emaksimo          #+#    #+#             */
/*   Updated: 2023/02/24 01:10:42 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_reserv(char *reserve)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(reserve) - i + 1));
	if (!str)
		return (NULL);
	i++;
	c = 0;
	while (reserve[i])
		str[c++] = reserve[i++];
	str[c] = '\0';
	free(reserve);
	return (str);
}

static char	*ft_get_line(char *reserve)
{
	int		i;
	char	*str;

	i = 0;
	if (!reserve[i])
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
		str[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
	{
		str[i] = reserve[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_rd_reserv(int fd, char *reserve)
{
	int		rd_byt;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rd_byt = 1;
	while (!ft_strchr(reserve, '\n') && rd_byt != 0)
	{
		rd_byt = read(fd, buf, BUFFER_SIZE);
		if (rd_byt == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_byt] = '\0';
		reserve = ft_strjoin(reserve, buf);
	}
	free(buf);
	return (reserve);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reserve[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	reserve[fd] = ft_rd_reserv(fd, reserve[fd]);
	if (!reserve[fd])
		return (NULL);
	line = ft_get_line(reserve[fd]);
	reserve[fd] = ft_reserv(reserve[fd]);
	return (line);
}
