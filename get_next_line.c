/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niebais <niebais@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:36:25 by niebais           #+#    #+#             */
/*   Updated: 2026/02/10 18:37:15 by niebais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (NULL);
	}
	str = fill_line_buffer(fd, str, buffer);
	if (!str)
		return (str = NULL);
	if (!str[0])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = extract_line(str);
	str = save_remainder(str);
	if (!line)
		return (NULL);
	return (line);
}

char	*fill_line_buffer(int fd, char *str, char *buffer)
{
	char	*tmp;
	int		i;

	i = 1;
	while ((!str || !ft_strchr(str, '\n')) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 && (free(buffer), free(str), 1))
			return (NULL);
		if (i == 0)
			break ;
		buffer[i] = '\0';
		if (str == NULL)
			str = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str, buffer);
			free(str);
			str = tmp;
		}
	}
	return (free(buffer), str);
}

char	*extract_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	return (line);
}

char	*save_remainder(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (!ft_strchr(str, '\n'))
	{
		free (str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	s = ft_substr(str, i, ft_strlen(str) - i);
	free(str);
	return (s);
}
