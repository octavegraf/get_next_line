/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:18:40 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/09 14:58:46 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_s_is_in_charset_bonus(char *s, char set)
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

char	*gnl_ft_strdup_bonus(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*dest;

	if (!s1)
		return (gnl_ft_strdup_bonus(""));
	i = 0;
	size = gnl_ft_strlen_bonus(s1);
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

char	*gnl_ft_strjoin_bonus(char const *s1, char const *s2)
{
	char	*s1s2;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (gnl_ft_strdup_bonus(s2));
	if (!s2)
		return (gnl_ft_strdup_bonus(s1));
	s1s2 = malloc((gnl_ft_strlen_bonus(s1) + gnl_ft_strlen_bonus(s2) + 1)
			* sizeof(char));
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

size_t	gnl_ft_strlen_bonus(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_ft_substr_bonus(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	size_t			i;
	size_t			size_len;

	if (!s)
		return (NULL);
	size_len = gnl_ft_strlen_bonus(s);
	if (start >= size_len)
		return (gnl_ft_strdup_bonus(""));
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

/*int	main(int ac, char **av)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	char	*line2;
	char	*line3;


	fd = 5;
	fd2 = 5;
	fd3 = 5;
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
	get_next_line(fd3);
	get_next_line(fd3);
	close(fd);
	close(fd2);
	close(fd3);
	ac = ac;
	return (0);
}*/