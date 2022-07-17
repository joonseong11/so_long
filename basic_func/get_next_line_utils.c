/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:57:42 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/17 16:13:34 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

size_t	g_strlen(const char *str)
{
	int	i;

	i = 0;
	if (*str == 0)
		return (i);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*g_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = g_strlen(s1);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*g_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	ourlen;

	if (s == NULL)
		return (NULL);
	i = 0;
	ourlen = g_strlen(s);
	if (start >= ourlen)
		return (g_strdup(""));
	if (ourlen - start < len)
		len = ourlen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*g_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*g_strjoin2(char const *s1, char const *s2, size_t len, char *str)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;

	i = 0;
	j = 0;
	len_s1 = g_strlen(s1);
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
