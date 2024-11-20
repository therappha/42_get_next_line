/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:13:15 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/20 18:55:35 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 5

#endif

char *get_next_line(int fd)
{
	static char		*next_line;
	static char		*readbuf;
	int				read_count;
	char			*result_line;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, readbuf, 0) < 0)
		return (NULL);
	while(new_line(next_line) == -1)
	{
		readbuf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!readbuf)
			return (NULL);
		read_count = read(fd, readbuf, BUFFER_SIZE);
		if (!read_count)
			return (free(readbuf), free(next_line), NULL);
		readbuf[read_count] = '\0';
		temp = ft_strjoin(next_line, readbuf);
		free(next_line);
		free(readbuf);
		next_line = temp;
	}
	result_line = copystr(next_line);
	temp = trimstr(next_line);
	next_line = temp;
	return (result_line);
}

int	ft_strsize(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

