/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:59:27 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/25 15:19:06 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *next_line)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(next_line), NULL);
	bytes_read = 1;
	while (!new_line(next_line) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && !next_line))
			return (free(buffer), free(next_line), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(next_line, buffer);
		if (!temp)
			return (free(buffer), free(next_line), NULL);
		free(next_line);
		next_line = temp;
	}
	return (free(buffer), next_line);
}

int	new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1len;
	int		s2len;

	s1len = 0;
	s2len = 0;
	if (s1)
		s1len = ft_strsize(s1);
	if (s2)
		s2len = ft_strsize(s2);
	str = (char *)malloc(s1len + s2len + 1);
	if (!str)
		return (NULL);
	if (s1)
		ft_strcpy(str, (char *)s1);
	if (s2)
		ft_strcpy((str + s1len), (char *)s2);
	return (str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndupmod(const char *str, int start, int end)
{
	char	*newstr;
	int		i;
	int		total_len;

	i = 0;
	total_len = end - start + 1;
	newstr = (char *)malloc(total_len + 1);
	if (!newstr)
		return (NULL);
	while (i < total_len)
	{
		newstr[i] = str[start];
		i++;
		start++;
	}
	newstr[i] = '\0';
	return (newstr);
}
