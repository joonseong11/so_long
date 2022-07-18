/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:08:11 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/18 14:46:49 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	check_map_close(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < g_strlen(info->str_map))
	{
		if ((i / (info->wid + 1)) == 0 && info->str_map[i] != '1' \
			&& i % (info->wid + 1) != info->wid)
			get_error(MAPERROR);
		else if ((i / (info->wid + 1)) > 0 \
			&& (i / (info->wid + 1)) < (size_t)info->hei - 1)
		{
			if (i % (info->wid + 1) == 0 || i \
				% (info->wid + 1) == info->wid - 1)
				if (info->str_map[i] != '1')
					get_error(MAPERROR);
		}
		else if ((i / (info->wid + 1)) == (size_t)info->hei - 1 \
			&& i % (info->wid + 1) < (size_t)info->wid \
				&& info->str_map[i] != '1')
			get_error(MAPERROR);
		++i;
	}
}

void	check_map_rectagular(t_info *info)
{
	int	i;

	i = 0;
	while (info->str_map[i])
	{
		while (info->str_map[i] && info->str_map[i] != '\n')
			++i;
		if (i % (info->wid + 1) != info->wid \
			&& i / (info->wid + 1) != info->hei - 1)
			get_error(MAPERROR);
		++i;
	}
}

void	check_map_component(t_info *info)
{
	size_t	i;

	i = 0;
	info->cnt_e = 0;
	info->cnt_c = 0;
	info->cnt_p = 0;
	while (i < g_strlen(info->str_map))
	{
		if (info->str_map[i] == 'E')
			++(info->cnt_e);
		else if (info->str_map[i] == 'C')
			++(info->cnt_c);
		else if (info->str_map[i] == 'P')
			++(info->cnt_p);
		else if (info->str_map[i] == '0' || info->str_map[i] == '1' \
			|| info->str_map[i] == '\n')
			;
		else
			get_error(MAPERROR);
		++i;
	}
	info->coin_on_map = info->cnt_c;
	if (info->cnt_e == 0 || info->cnt_c == 0 || info->cnt_p != 1)
		get_error(MAPERROR);
}

void	init_map(t_info *info, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		get_error(OTHER);
	line = get_next_line(fd);
	info->wid = g_strlen(line) - 1;
	info->hei = 0;
	info->str_map = ft_strdup("");
	while (line)
	{
		if (*line == '\n')
			get_error(MAPERROR);
		info->str_map = g_strjoin(info->str_map, line);
		free(line);
		line = get_next_line(fd);
		++(info->hei);
	}
	close(fd);
	init_info(info);
	check_map_component(info);
	check_map_rectagular(info);
	check_map_close(info);
	adapt_image(info);
}
