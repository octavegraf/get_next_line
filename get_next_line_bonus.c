/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:07:18 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/09 14:52:54 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_read_until_nl_bonus(int fd, char *current)
{
	char	*buffer;
	char	*temp;
	int		read_status;

	read_status = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((read_status > 0) && (gnl_s_is_in_charset(current, '\n') < 0))
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status < 0)
		{
			return (free(buffer), buffer = NULL, free(current), NULL);
		}
		if (read_status == 0)
			return (free(buffer), buffer = NULL, current);
		buffer[read_status] = '\0';
		temp = gnl_ft_strjoin(current, buffer);
		free(current);
		current = temp;
	}
	return (free(buffer), buffer = NULL, current);
}

static char	*gnl_cut_line_bonus(char **current)
{
	char	*result;
	char	*temp;
	int		n;

	if (!current || !*current)
		return (NULL);
	n = gnl_s_is_in_charset(*current, '\n');
	if (n >= 0)
	{
		result = gnl_ft_substr(*current, 0, n + 1);
		temp = gnl_ft_substr(*current, n + 1,
				((gnl_ft_strlen(*current) - n) - 1));
		free(*current);
		*current = temp;
	}
	else
	{
		result = gnl_ft_strdup(*current);
		free(*current);
		*current = NULL;
	}
	return (result);
}

void	gnl_free_everything_bonus(char ***current)
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

int	gnl_is_there_something_to_free_bonus(char **current)
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

char	*get_next_line_bonus(int fd)
{
	static char	**current;
	int			i;

	i = -1;
	if ((fd >= FOPEN_MAX || fd < 0 || BUFFER_SIZE <= 0))
		return (NULL);
	if (!current)
	{
		current = malloc(sizeof(char *) * FOPEN_MAX);
		if (!current)
			return (NULL);
		while (++i < FOPEN_MAX)
			current[i] = NULL;
	}
	current[fd] = gnl_read_until_nl(fd, current[fd]);
	if (!(current[fd]) || !(current[fd][0]))
	{
		free(current[fd]);
		current[fd] = NULL;
		if (!is_there_something_to_free(current))
			free_everything(&current);
		return (NULL);
	}
	return (cut_line(&current[fd]));
}
