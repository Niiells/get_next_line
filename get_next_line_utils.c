/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niebais <niebais@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:36:44 by niebais           #+#    #+#             */
/*   Updated: 2026/02/10 18:37:15 by niebais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *src)
{
	return (ft_substr(src, 0, ft_strlen(src)));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	n = 0;
	str = (char *) malloc((ft_strlen((char *) s1)
				+ ft_strlen((char *) s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[n] = s1[i];
		i++;
		n++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[n] = s2[i];
		i++;
		n++;
	}
	str[n] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t) start > ft_strlen((char *) s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *) s + start))
		len = ft_strlen((char *)s + start);
	s2 = (char *)ft_calloc(len + 1, sizeof(char));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	return (s2);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (size != 0 && nmemb > (SIZE_MAX) / size)
		return (NULL);
	if (!nmemb || !size)
		return (malloc(0));
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	while (i < (nmemb * size))
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
