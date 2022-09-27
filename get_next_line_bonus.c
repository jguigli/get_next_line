/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguigli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:25:57 by jguigli           #+#    #+#             */
/*   Updated: 2021/12/14 17:26:01 by jguigli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_end_line(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*readbuffer(int fd, char *tank)
{
	int		r;
	char	*temp;

	r = 1;
	if (!tank)
		tank = ft_strdup("");
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!check_end_line(tank) && r > 0)
	{
		r = read(fd, temp, BUFFER_SIZE);
		if (r == -1)
			return (free(temp), free(tank), NULL);
		temp[r] = '\0';
		tank = ft_strjoin(tank, temp);
	}
	free (temp);
	return (tank);
}

char	*save(char *tank)
{
	char	*save;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!tank)
		return (free(tank), NULL);
	if (tank[0] == '\0')
		return (free(tank), NULL);
	while (tank[i] && tank[i] != '\n')
		i++;
	save = (char *)malloc(sizeof(char) * ((ft_strlen(tank) - i) + 1));
	if (!save)
		return (free(tank), NULL);
	if (tank[i] == '\n')
		i++;
	while (tank[i] != '\0')
		save[j++] = tank[i++];
	save[j] = '\0';
	free(tank);
	return (save);
}

char	*get_line(char *str)
{
	char		*line;
	size_t		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = ft_substr(str, 0, i + 1);
	else
		line = ft_substr(str, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*tank[1024];

	if ((fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	tank[fd] = readbuffer(fd, tank[fd]);
	if (!tank[fd])
		return (NULL);
	line = get_line(tank[fd]);
	if (!line)
		return (NULL);
	tank[fd] = save(tank[fd]);
	if (!tank[fd])
		return (free(line), NULL);
	return (line);
}
