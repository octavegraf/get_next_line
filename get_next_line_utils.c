/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:18:40 by ocgraf            #+#    #+#             */
/*   Updated: 2025/05/02 22:03:27 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	if (!(char)c)
		return (str + i);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*c_cut_string(char *s, char set)
{
	size_t	i;
	char	*result;

	i = 0;
	while (s[i] && !ft_strchr(s, set))
		i++;
	result = malloc(sizeof(char) * i);
	i = 0;
	while (s[i] && !ft_strchr(s, set))
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	s1s2 = malloc((size + 1) * sizeof(char));
	if (!s1s2)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s1s2[i] = s1[i];
		i++;
	}
	while ((i - ft_strlen(s1)) < ft_strlen(s2))
	{
		s1s2[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	s1s2[i] = '\0';
	return (s1s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int			i;
	char					*subs;

	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

int	main(void)
{
	int		fd;
	char	*x;

	fd = open("lorem_ipsum", O_RDONLY);
	x = get_next_line(fd);
	while (x)
		x = get_next_line(fd);
	return (0);
}
