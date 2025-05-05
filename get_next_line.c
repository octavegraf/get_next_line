/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:07:18 by ocgraf            #+#    #+#             */
/*   Updated: 2025/05/05 17:49:55 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*temp;
	int			fd_status;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!temp)
		temp = buffer;
	fd_status = read(fd, buffer, BUFFER_SIZE);
	while (!s_is_in_charset(temp, '\n') && fd_status > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		temp = ft_strjoin(temp, buffer);
		fd_status = read(fd, buffer, BUFFER_SIZE);
	}
	if (fd_status <= 0 && !*temp)
	{
		free(buffer);
		free(temp);
		return (NULL);
	}
	buffer = ft_substr(temp, 0, s_is_in_charset(temp, '\n'));
	return (temp = ft_substr(temp, s_is_in_charset(temp, '\n') + 1,
			ft_strlen(temp) - s_is_in_charset(temp, '\n')), buffer);
}
