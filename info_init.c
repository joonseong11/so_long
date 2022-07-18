/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:00:34 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/18 14:33:27 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_info(t_info *info)
{
	int	pixel;

	pixel = 64;
	info->mlx = mlx_init();
	info->win = mlx_new_window \
		(info->mlx, 64 * info->wid, 64 * info->hei, "so_long");
	info->img = malloc(sizeof(t_img));
	if (info->img == NULL)
		get_error(ALLOC);
	info->img->tile = mlx_xpm_file_to_image \
		(info->mlx, "./images/resized_tile2.xpm", &pixel, &pixel);
	info->img->wall = mlx_xpm_file_to_image \
		(info->mlx, "./images/resized_wall2.xpm", &pixel, &pixel);
	info->img->door = mlx_xpm_file_to_image \
		(info->mlx, "./images/resized_newdoor.xpm", &pixel, &pixel);
	info->img->coin = mlx_xpm_file_to_image \
		(info->mlx, "./images/resized_newcoin.xpm", &pixel, &pixel);
	info->img->hero = mlx_xpm_file_to_image \
		(info->mlx, "./images/resized_hero2.xpm", &pixel, &pixel);
}
