/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:15:29 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/03 14:41:15 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*readbuffer(int fd, char *tank);
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *dest, char *src);
int		check_end_line(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif