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
    static char *storage = NULL;
	char		*buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0) 
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
	{
		return (NULL);
	}
	storage = fill_line_buffer(fd, storage, buffer);
	return (0);
}

char	*fill_line_buffer(int fd, char *storage, char *buffer)
{
	char *temp;
	int readcount;
	
	readcount = 1;
	while((!storage || !ft_strchr(storage, '\n')) && readcount != 0)
	{
		readcount = read(fd, buffer, BUFFER_SIZE);
		if (readcount == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[readcount] = '\0';
		temp = ft_strjoin(storage, buffer);
		free(storage);
		storage = temp;
	}
	return(storage);
}

int main (void)
{
    int fd = 1;
    return (0);
}

