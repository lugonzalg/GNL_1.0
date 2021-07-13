/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:46:59 by lugonzal          #+#    #+#             */
/*Updated: 2021/06/13 18:47:00 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "get_next_line.h"

static int	fail_size(char *buffer)
{
	free(buffer);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buffer;
	ssize_t		size;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd == 2)
		return (-1);
	size = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	while (!ft_strchr(str, '\n') && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (fail_size(buffer));
		buffer[size] = '\0';
		str = ft_strjoin(str, buffer);
	}
	*line = cutstr(str, 0, len_c(str, '\n'), 0);
	str = cutstr(str, len_c(str, '\n') + 1, len_c(str, 0) - len_c(*line, 0), 1);
	free(buffer);
	if (!size)
		return (0);
	return (1);
}
