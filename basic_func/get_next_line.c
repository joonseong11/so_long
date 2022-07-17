/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:57:45 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/17 20:44:22 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	*g_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (s1 == NULL)
		return (g_strdup(s2));
	if (s2 == NULL)
		return (g_strdup(s1));
	len = g_strlen(s1) + g_strlen(s2);
	str = malloc(sizeof(char) * (len) + 1);
	if (str == NULL)
		return (NULL);
	str = g_strjoin2(s1, s2, len, str);
	free((void *)s1);
	return (str);
}

char	*leave_newtemp(char *temp)
{
	char	*newtemp;
	size_t	len_newtemp;

	if (g_strchr(temp, '\n') == 0)
		return (NULL);
	len_newtemp = g_strlen(temp) - (g_strchr(temp, '\n') - temp + 1);
	newtemp = g_substr(temp, (g_strchr(temp, '\n') - temp + 1), len_newtemp);
	if (newtemp == NULL || *newtemp == '\0')
	{
		free(temp);
		free(newtemp);
		return (NULL);
	}
	free(temp);
	return (newtemp);
}

char	*line_truncate(char *temp)
{
	char	*line;

	if (g_strchr(temp, '\n') == 0)
		return (temp);
	line = g_substr(temp, 0, (g_strchr(temp, '\n') - temp + 1));
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*read_buf(int fd, char *temp)
{
	ssize_t	check;
	char	*buf;

	check = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
	{
		free(buf);
		return (NULL);
	}
	buf[0] = '\0';
	while (g_strchr(buf, '\n') == 0 && check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		buf[check] = '\0';
		if (check < 0)
		{
			free(buf);
			return (NULL);
		}
		if (check > 0)
			temp = g_strjoin(temp, buf);
	}
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = read_buf(fd, temp);
	if (temp == NULL)
		return (NULL);
	line = line_truncate(temp);
	temp = leave_newtemp(temp);
	return (line);
}
