/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:20:10 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/15 17:20:10 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	str = (char *)malloc(strsize(s1) + strsize(s2) + 1);
	if (!str)
		return (NULL);
	ft_strcpy(str, (char *)s1);
	ft_strcpy((str + strsize(s1)), (char *)s2);
	free(s2);
	return (str);
}

int	new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*copystr(char *str)
{
	int		i;
	int		n;
	char	*result;

	i = 0;
	n = new_line(str);
	result = (char *)malloc(sizeof(char) * (n + 1));

	while (*str && i < n)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = ('\0');
	return (result);
}

char	*trimstr(char *str)
{
	char *result;
	int	len_n;
	int	len;
	int	i;

	i = 0;
	len_n = new_line(str) + 1;
	len = strsize(str);
	result = (char *)malloc(sizeof(char) * (len - len_n + 1));
	while(i < (len - len_n))
	{
		result[i] = str[len_n + i];
		i++;
	}
	result[i] = '\0';
	return (result);
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


