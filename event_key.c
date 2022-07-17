/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:54:51 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/18 01:24:00 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long_exit(void)
{
	exit(0);
}

void	move_hero_w(t_info *info)
{
	int	i;

	i = 0;
	while (info->str_map[i] && info->str_map[i] != 'P')
		++i;
	if (i / (info->wid + 1) != 0 \
		&& info->str_map[i - (info->wid + 1)] != '1')
	{
		if (info->str_map[i - (info->wid + 1)] == 'C')
			--(info->coin_on_map);
		else if (info->str_map[i - (info->wid + 1)] == 'E')
		{
			if (info->coin_on_map != 0)
				return ;
			else
				exit(0);
		}
		info->str_map[i - (info->wid + 1)] = 'P';
		info->str_map[i] = '0';
		++(info->step);
		adapt_image(info);
		printf("current step : %d\n", info->step);
	}
}

void	move_hero_s(t_info *info)
{
	int	i;

	i = 0;
	while (info->str_map[i] && info->str_map[i] != 'P')
		++i;
	if (i / (info->wid + 1) != info->hei - 1 \
		&& info->str_map[i + (info->wid + 1)] != '1')
	{
		if (info->str_map[i + (info->wid + 1)] == 'C')
			--(info->coin_on_map);
		else if (info->str_map[i + (info->wid + 1)] == 'E')
		{
			if (info->coin_on_map != 0)
				return ;
			else
				exit(0);
		}
		info->str_map[i + (info->wid + 1)] = 'P';
		info->str_map[i] = '0';
		++(info->step);
		adapt_image(info);
		printf("current step : %d\n", info->step);
	}
}

void	move_hero_a(t_info *info)
{
	int	i;

	i = 0;
	while (info->str_map[i] && info->str_map[i] != 'P')
		++i;
	if (i % (info->wid + 1) != 0 \
		&& info->str_map[i - 1] != '1')
	{
		if (info->str_map[i - 1] == 'C')
			--(info->coin_on_map);
		else if (info->str_map[i - 1] == 'E')
		{
			if (info->coin_on_map != 0)
				return ;
			else
				exit(0);
		}
		info->str_map[i - 1] = 'P';
		info->str_map[i] = '0';
		++(info->step);
		adapt_image(info);
		printf("current step : %d\n", info->step);
	}
}

void	move_hero_d(t_info *info)
{
	int	i;

	i = 0;
	while (info->str_map[i] && info->str_map[i] != 'P')
		++i;
	if (i % (info->wid + 1) != info->wid \
		&& info->str_map[i + 1] != '1')
	{
		if (info->str_map[i + 1] == 'C')
			--(info->coin_on_map);
		else if (info->str_map[i + 1] == 'E')
		{
			if (info->coin_on_map != 0)
				return ;
			else
				exit(0);
		}
		info->str_map[i + 1] = 'P';
		info->str_map[i] = '0';
		++(info->step);
		adapt_image(info);
		printf("current step : %d\n", info->step);
	}
}
