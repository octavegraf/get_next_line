/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:07:18 by ocgraf            #+#    #+#             */
/*   Updated: 2025/05/02 22:08:59 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	static char		*result;
	size_t			bytes_read;
	int				read_info;

	read_info = 0;
	if (!fd)
		return (NULL);
	if (!buffer)
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
	bytes_read = ft_strlen(buffer);
	if ((!bytes_read) || (bytes_read == BUFFER_SIZE))
		read_info = read(fd, buffer, BUFFER_SIZE);
	if ((!read_info) || (read_info == -1))
		return (NULL);
	bytes_read = ft_strlen(c_cut_string(buffer, '\n'));
	if (!result)
		result = malloc(sizeof(char) * BUFFER_SIZE);
	result = ft_strjoin(result, c_cut_string(buffer, '\n'));
	buffer = ft_substr(buffer, bytes_read - 1, ft_strlen(buffer) - bytes_read);
	if (ft_strchr(result, '\n'))
		return (result);
	else
		return (get_next_line(fd));
}
