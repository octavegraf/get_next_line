/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:07:18 by ocgraf            #+#    #+#             */
/*   Updated: 2025/05/10 20:30:44 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_until_nl(int fd, char *current)
{
	char	*buffer;
	char	*temp;
	int		read_status;

	read_status = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((read_status > 0) && (s_is_in_charset(current, '\n') < 0))
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status < 0)
			return (free(buffer), buffer = NULL, free(current), NULL);
		if (read_status == 0)
			return (free(buffer), buffer = NULL, current);
		buffer[read_status] = '\0';
		temp = ft_strjoin(current, buffer);
		free(current);
		current = temp;
	}
	return (free(buffer), buffer = NULL, current);
}

static char	*cut_line(char **current)
{
	char	*result;
	char	*temp;
	int		n;

	n = s_is_in_charset(*current, '\n');
	if (n >= 0)
	{
		result = ft_substr(*current, 0, n + 1);
		temp = ft_substr(*current, n + 1, ((ft_strlen(*current) - n) - 1));
		free(*current);
		*current = temp;
	}
	else
	{
		result = ft_strdup(*current);
		free(*current);
		*current = NULL;
	}
	return (result);
}

void	free_everything(char ***current)
{
	int	i;

	i = -1;
	while (++i < FOPEN_MAX)
	{
		if ((*current)[i])
		{
			free((*current)[i]);
			(*current)[i] = NULL;
		}
	}
	free(*current);
	(*current) = NULL;
}

int	is_there_something_to_free(char **current)
{
	int	i;

	if (!current)
		return (0);
	i = -1;
	while (++i < FOPEN_MAX)
	{
		if (current[i])
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	**current;
	int			i;

	i = -1;
	if (fd >= FOPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
	{
		if (current)
			free_everything(&current);
		return (NULL);
	}
	if (!current)
	{
		current = malloc(sizeof(char *) * FOPEN_MAX);
		if (!current)
			return (NULL);
		while (++i < FOPEN_MAX)
			current[i] = NULL;
	}
	current[fd] = read_until_nl(fd, current[fd]);
	if (!(current[fd]) || !(current[fd][0]))
		return (free_everything(&current), NULL);
	if (!is_there_something_to_free(current))
		free_everything(&current);
	return (cut_line(&current[fd]));
}
