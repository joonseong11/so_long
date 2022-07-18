/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:54:21 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/18 13:59:52 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_info *info, int i, void *obj)
{
	mlx_put_image_to_window(info->mlx, info->win, obj, \
		(i % (info->wid + 1)) * 64, (i / (info->wid + 1)) * 64);
}

void	adapt_image(t_info *info)
{
	int	i;

	i = 0;
	while (info->str_map[i])
	{
		if (info->str_map[i] == '0')
			put_image(info, i, info->img->tile);
		else if (info->str_map[i] == '1')
			put_image(info, i, info->img->wall);
		else if (info->str_map[i] == 'E')
			put_image(info, i, info->img->door);
		else if (info->str_map[i] == 'C')
			put_image(info, i, info->img->coin);
		else if (info->str_map[i] == 'P')
		{
			put_image(info, i, info->img->tile);
			put_image(info, i, info->img->hero);
		}
		++i;
	}
}
