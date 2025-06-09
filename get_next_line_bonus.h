/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:21:12 by ocgraf            #+#    #+#             */
/*   Updated: 2025/06/09 14:51:39 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char		*get_next_line_bonus(int fd);
int			gnl_s_is_in_charset_bonus(char *s, char set);
char		*gnl_ft_strchr_bonus(const char *s, int c);
char		*gnl_ft_strjoin_bonus(char const *s1, char const *s2);
size_t		gnl_ft_strlen_bonus(const char *s);
char		*gnl_ft_substr_bonus(char const *s, unsigned int start, size_t len);
char		*gnl_ft_strdup_bonus(const char *s1);
char		*gnl_read_until_nl_bonus(int fd, char *current);

#endif