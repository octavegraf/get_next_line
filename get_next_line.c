/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:07:18 by ocgraf            #+#    #+#             */
/*   Updated: 2025/05/07 12:33:25 by ocgraf           ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*result;
	char		*temp;
	static char	*storage;
	int			fd_status;

	if (fd <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	if (!storage)
		return (free(buffer), NULL);
	fd_status = 1;
	while ((fd_status > 0) && !s_is_in_charset(storage, '\n'))
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		fd_status = read(fd, buffer, BUFFER_SIZE);
		if (fd_status == -1)
			return (free(storage), NULL);
		temp = ft_strdup(storage);
		if (!temp)
			return (free(storage), free(buffer), NULL);
		free(storage);
		storage = ft_strjoin(temp, buffer);
		if (!storage)
			return (free(buffer), free(temp), NULL);
		free(temp);
	}
	free(buffer);
	if (s_is_in_charset(storage, '\n'))
		result = ft_substr(storage, 0, s_is_in_charset(storage, '\n') + 1);
	else
		result = ft_strdup(storage);
	if (!result || !ft_strlen(result))
		return (free(storage), free(buffer), free(result), free(temp), NULL);
	temp = ft_strdup(storage);
	if (!temp)
		return (free(storage), free(result), NULL);
	free(storage);
	storage = ft_substr(temp, ft_strlen(result),
			ft_strlen(temp) - ft_strlen(result));
	if (!storage)
		return(free(temp), free(result), NULL);
	return (result);
}
