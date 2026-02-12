/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niebais <niebais@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:37:33 by niebais           #+#    #+#             */
/*   Updated: 2026/02/10 18:37:34 by niebais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*fill_line_buffer(int fd, char *storage, char *buffer);

#endif
