/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:07:46 by lugonzal          #+#    #+#             */
/*Updated: 2021/06/08 11:08:10 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

size_t	len_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*n_str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	n_str = (char *)malloc(sizeof(char) * (len_c(s1, 0) + len_c(s2, 0) + 1));
	if (!n_str)
		return (NULL);
	while (s1[++i])
		n_str[i] = s1[i];
	while (s2[++j])
		n_str[i + j] = s2[j];
	n_str[i + j] = '\0';
	free(s1);
	return (n_str);
}

char	*cutstr(char *str, unsigned int begin, size_t length, int on)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (on && !str[len_c(str, 0)] && !str[len_c(str, '\n')])
	{
		free(str);
		return (NULL);
	}
	if (on)
		length -= len_c(str, '\n');
	new_str = malloc(sizeof(char) * (length + 1));
	if (!new_str)
		return (NULL);
	while (length > i)
	{
		new_str[i] = str[begin + i];
		i++;
	}
	new_str[i] = '\0';
	if (on)
		free(str);
	return (new_str);
}
