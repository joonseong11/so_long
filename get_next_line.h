/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:02:04 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/17 16:13:15 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1042
# include <unistd.h>
# include <stdlib.h>

size_t	g_strlen(const char *str);
char	*g_strdup(const char *s1);
char	*g_substr(char const *s, unsigned int start, size_t len);
char	*g_strchr(const char *s, int c);
char	*g_strjoin(char const *s1, char const *s2);
char	*g_strjoin2(char const *s1, char const *s2, size_t len, char *str);
char	*get_next_line(int fd);
char	*read_buf(int fd, char *temp);
char	*line_truncate(char *temp);
char	*leave_newtemp(char *temp);
#endif
