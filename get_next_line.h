/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:39:09 by rafaelfe          #+#    #+#             */
/*   Updated: 2024/11/18 18:42:42 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H


#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdio.h>


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


char	*ft_strjoin(char *s1, char *s2);
char	*trimstr(char *str);
char	*copystr(char *str);
int		new_line(char *str);
char	*get_next_line(int fd);
int	ft_strsize(const char *str);
char	*ft_strcpy(char *dest, char *src);

#endif
