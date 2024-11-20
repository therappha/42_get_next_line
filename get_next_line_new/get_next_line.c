/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:55:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/20 19:13:02 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || (read(fd, 0, 0) < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = copystr(buffer);
	buffer = trimstr(buffer);
	return (line);
}
int	ft_strsize(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*copystr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0') // && str[i + 1] removes the if
		i++;
	if (str[i] == '\0' && i > 0)
		--i;
	return (ft_strndupmod(str, 0, i));
}
char *trimstr(char *str)
{
	int	str_size;
	int	i;
	char	*result;

	i = 0;
	str_size = ft_strsize(str) - 1;
	while (str[i] != '\n' && str[i + 1]) // if \n or the index previous than '\0'
		i++;
	++i;
	if (!str[i])
		result = ft_strndupmod("", 0, 0);
	else
		result = ft_strndupmod(str, i, str_size);
	free(str);
	return (result);
}
