/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:07:18 by ocgraf            #+#    #+#             */
/*   Updated: 2025/05/10 18:56:34 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_nl(int fd, char *current)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		bytes_read;
}
char	*get_next_line(int fd)
{
	static char	*current;

	current = NULL;
}
