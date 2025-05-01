/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:18:40 by ocgraf            #+#    #+#             */
/*   Updated: 2025/05/01 20:12:49 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	c_is_in_charset(char c, char set)
{
	if (c == set)
		return (1);
	return (0);
}

char	*cut_string(char *s, char set)
{
	size_t	i;
	char	*result;

	i = 0;
	while (s[i] && !c_is_in_charset(s[i], set))
		i++;
	result = malloc(sizeof(char) * i);
	i = 0;
	while (s[i] && !c_is_in_charset(s[i], set))
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	main(void)
{
	int	fd;

	fd = open("lorem_ipsum", O_RDONLY);
}
