/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:07:18 by ocgraf            #+#    #+#             */
/*   Updated: 2025/05/06 15:23:12 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	str = s;
	while (n > 0)
	{
		str[i] = 0;
		i++;
		n--;
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*temp;
	int			fd_status;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!temp)
		temp = "";
	fd_status = read(fd, buffer, BUFFER_SIZE);
	while (!s_is_in_charset(temp, '\n') && fd_status > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		temp = ft_strjoin(temp, buffer);
		ft_bzero(buffer, ft_strlen(buffer));
		if (!temp)
			return (NULL);
		if (!s_is_in_charset(temp, '\n'))
			fd_status = read(fd, buffer, BUFFER_SIZE);
	}
	if (fd_status <= 0 && !temp)
		return (NULL);
	if (buffer)
		free(buffer);
	buffer = NULL;
	if (fd_status > 0)
		buffer = ft_substr(temp, 0, s_is_in_charset(temp, '\n'));
	temp = ft_substr(temp, s_is_in_charset(temp, '\n') + 1,
			ft_strlen(temp) - s_is_in_charset(temp, '\n'));
	return (buffer);
	if (!*temp)
		return (free(temp), temp = NULL, NULL);
	return (buffer);
}	
