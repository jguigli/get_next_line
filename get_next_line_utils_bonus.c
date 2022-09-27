/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:26:35 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/14 17:26:38 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!src || !dest)
		return (NULL);
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cat;
	size_t	length;

	if (!s1 && !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	cat = (char *)malloc(sizeof(char) * (length + 1));
	if (!cat)
		return (NULL);
	cat[0] = '\0';
	cat = ft_strcat(cat, s1);
	cat = ft_strcat(cat, s2);
	cat[length] = '\0';
	free(s1);
	return (cat);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen((char *)s);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	if (start < slen)
	{
		while (s[start + i] && i < len)
		{
			newstr[i] = s[start + i];
			i++;
		}
	}
	newstr[i] = '\0';
	return (newstr);
}
