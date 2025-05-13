/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:18:40 by ocgraf            #+#    #+#             */
/*   Updated: 2025/05/12 15:52:43 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	s_is_in_charset(char *s, char set)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == set)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*dest;

	i = 0;
	size = ft_strlen(s1);
	dest = malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < size + 1)
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1s2 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s1s2)
		return (NULL);
	i = -1;
	while (s1[++i])
		s1s2[i] = s1[i];
	j = 0;
	while (s2[j])
		s1s2[i++] = s2[j++];
	s1s2[i] = '\0';
	return (s1s2);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	size_t			i;
	size_t			size_len;

	if (!s)
		return (NULL);
	size_len = ft_strlen(s);
	if (start >= size_len)
		return (ft_strdup(""));
	if (len > size_len - start)
		len = size_len - start;
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

/* int	main(void)
{
	int		fd;
	char	*x;

	fd = open("lorem_ipsum", O_RDONLY);
	x = get_next_line(fd);
	while (x)
		x = get_next_line(fd);
	return (0);
} */

/* #include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}*/
/* int	main(void)
{
	int		fd;
	char	*x;

	fd = open("lorem_ipsum", O_RDONLY);
	x = get_next_line(fd);
	while (x)
		x = get_next_line(fd);
	return (0);
}*/

/* int	main(int ac, char **av)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	char	*line2;
	char	*line3;

	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	while (line || line2 || line3)
	{
		if (line)
			printf("(fd 1) %s", line);
		if (line2)
			printf("(fd 2) %s", line2);
		if (line3)
			printf("(fd 3) %s", line3);
		free(line);
		free(line2);
		free(line3);
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
} */