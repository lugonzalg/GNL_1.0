/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 15:53:22 by lugonzal          #+#    #+#             */
/*Updated: 2021/06/20 15:53:31 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include "get_next_line_bonus.h"
#include <stdlib.h>

static int	fail_size(char *buffer)
{
	free(buffer);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[10200];
	char		*buffer;
	ssize_t		size;

	if (fd == -1 || !line || BUFFER_SIZE < 1 || fd > 10200 || fd == 2)
		return (-1);
	size = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	while (!ft_strchr(str[fd], '\n') && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (fail_size(buffer));
		buffer[size] = '\0';
		str[fd] = ft_strjoin(str[fd], buffer);
	}
	*line = cutstr(str[fd], 0, len_c(str[fd], '\n'), 0);
	str[fd] = cutstr(str[fd], len_c(str[fd], '\n') + 1, len_c(str[fd], 0), 1);
	free(buffer);
	if (!size)
		return (0);
	return (1);
}
