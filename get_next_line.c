/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:07:18 by ocgraf            #+#    #+#             */
/*   Updated: 2025/05/02 19:48:12 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	static char		*result;
	size_t			bytes_read;
	int				read_info;

	if (!fd)
		return (NULL);
	bytes_read = ft_strlen(buffer);
	if ((!bytes_read) || (bytes_read == BUFFER_SIZE))
		read_info = (fd, buffer, BUFFER_SIZE);
	if ((!read_info) || (read_info == -1))
		return (NULL);
	if (c_is_in_charset(result, '\n'))
		free(result);
	else
	{
		result = ft_strjoin(result, c_cut_string(buffer, '\n'));
		buffer = ft_substr(buffer, 0, ft_strlen(c_cut_string(buffer, '\n')));
	}
	if (c_is_in_charset(result, '\n'))
		return (result);
	else
		get_next_line(fd);
