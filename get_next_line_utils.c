/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:18:40 by ocgraf            #+#    #+#             */
/*   Updated: 2025/05/02 19:48:27 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	c_is_in_charset(char c, char set)
{
	if (c == set)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*c_cut_string(char *s, char set)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	s1s2 = malloc((size + 1) * sizeof(char));
	if (!s1s2)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s1s2[i] = s1[i];
		i++;
	}
	while ((i - ft_strlen(s1)) < ft_strlen(s2))
	{
		s1s2[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	s1s2[i] = '\0';
	return (s1s2);
}

int	main(void)
{
	int	fd;
	fd = open("lorem_ipsum", O_RDONLY);
	
}
