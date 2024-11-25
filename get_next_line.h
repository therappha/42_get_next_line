/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:39:09 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/25 15:27:25 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 5

# endif

char	*ft_strjoin(char *s1, char *s2);
char	*trimstr(char *str);
char	*copystr(char *str);
int		new_line(char *str);
char	*get_next_line(int fd);
int		ft_strsize(const char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_read(int fd, char *next_line);
char	*ft_strndupmod(const char *str, int start, int end);

#endif
