/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:08:11 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/18 01:20:04 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void adapt_image(t_info *info)
{
	int i;

	i = 0;
	while (info->str_map[i])
	{
		if (info->str_map[i] == '0')
			mlx_put_image_to_window(info->mlx, info->win, info->img->tile, (i % (info->wid + 1)) * 64, (i / (info->wid + 1)) * 64);
		else if (info->str_map[i] == '1')
			mlx_put_image_to_window(info->mlx, info->win, info->img->wall, (i % (info->wid + 1)) * 64, (i / (info->wid + 1)) * 64);
		else if (info->str_map[i] == 'E')
			mlx_put_image_to_window(info->mlx, info->win, info->img->door, (i % (info->wid + 1)) * 64, (i / (info->wid + 1)) * 64);
		else if (info->str_map[i] == 'C')
		{
			mlx_put_image_to_window(info->mlx, info->win, info->img->tile, (i % (info->wid + 1)) * 64, (i / (info->wid + 1)) * 64);
			mlx_put_image_to_window(info->mlx, info->win, info->img->coin, (i % (info->wid + 1)) * 64, (i / (info->wid + 1)) * 64);
		}
		else if (info->str_map[i] == 'P')
		{
			mlx_put_image_to_window(info->mlx, info->win, info->img->tile, (i % (info->wid + 1)) * 64, (i / (info->wid + 1)) * 64);
			mlx_put_image_to_window(info->mlx, info->win, info->img->hero, (i % (info->wid + 1)) * 64, (i / (info->wid + 1)) * 64);
		}
		++i;
	}
}

void check_map_close(t_info *info)
{
	size_t i;

	i = 0;
	while (i < g_strlen(info->str_map))
	{
		if ((i / (info->wid + 1)) == 0 && info->str_map[i] != '1' \
			&& i % (info->wid + 1) != info->wid)
			get_error(MAPERROR);
		else if ((i / (info->wid + 1)) > 0 \
			&& (i / (info->wid + 1)) < (size_t)info->hei)
		{
			if (i % (info->wid + 1) == 0 || i % (info->wid + 1) == info->wid - 1)
				if (info->str_map[i] != '1')
					get_error(MAPERROR);
		}
		else if ((i / (info->wid + 1)) == (size_t)info->hei - 1 \
			&& info->str_map[i] != '1')
			get_error(MAPERROR);
		++i;
	}
}

void check_map_rectagular(t_info *info)
{
	int i;

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

void check_map_component(t_info *info)
{
	size_t i;
	int cnt_E;
	int cnt_C;
	int cnt_P;

	i = 0;
	cnt_E = 0;
	cnt_C = 0;
	cnt_P = 0;
	while (i < g_strlen(info->str_map))
	{
		if (info->str_map[i] == 'E')
			++cnt_E;
		else if (info->str_map[i] == 'C')
			++cnt_C;
		else if (info->str_map[i] == 'P')
			++cnt_P;
		++i;
	}
	info->coin_on_map = cnt_C;
	if (cnt_E == 0 || cnt_C == 0 || cnt_P != 1)
		get_error(MAPERROR);
}

void init_map(t_info *info, char *filename)
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		get_error(OTHER);
	line = get_next_line(fd);
	info->wid = g_strlen(line) - 1;
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
	check_map_component(info);
	check_map_rectagular(info);
	printf("%s\n", info->str_map);
	check_map_close(info);
	adapt_image(info);
}