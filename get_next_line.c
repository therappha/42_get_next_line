/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:13:15 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/15 20:55:12 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 5

#endif

char *get_next_line(int fd)
{
	static char	*next_line;
	char		*readbuf;
	int			read_count;
	char		*result_line;

	readbuf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, readbuf, 0) < 0)
		return (NULL);

	while(new_line(next_line) == -1)
	{
		readbuf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!readbuf)
			return (NULL);
		read_count = read(fd, readbuf, BUFFER_SIZE);
		if (read_count == 0)
		{
			free(readbuf);
			break;
		}
		readbuf[read_count] = '\0';
		next_line = ft_strjoin(next_line, readbuf);
	}
	result_line = copystr(next_line);
	next_line = trimstr(next_line);
	return (result_line);
}

int	strsize(const char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

