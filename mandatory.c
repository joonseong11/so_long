/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:59:54 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/18 01:14:10 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int so_long_key_press(int keycode, void *info)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W)
		move_hero_w((t_info *)info);
	else if (keycode == KEY_S)
		move_hero_s((t_info *)info);
	else if (keycode == KEY_A)
		move_hero_a((t_info *)info);
	else if (keycode == KEY_D)
		move_hero_d((t_info *)info);
	return (0);
}

void init_info(t_info *info)
{
	int pixel;

	pixel = 64;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1500, 1024, "so_long");
	info->img = malloc(sizeof(t_img));
	if (info->img == NULL)
		get_error(ALLOC);
	info->img->tile = mlx_xpm_file_to_image(info->mlx, "./images/resized_tile2.xpm", &pixel, &pixel);
	info->img->wall = mlx_xpm_file_to_image(info->mlx, "./images/resized_wall2.xpm", &pixel, &pixel);
	info->img->door = mlx_xpm_file_to_image(info->mlx, "./images/resized_newdoor.xpm", &pixel, &pixel);
	info->img->coin = mlx_xpm_file_to_image(info->mlx, "./images/resized_newcoin.xpm", &pixel, &pixel);
	info->img->hero = mlx_xpm_file_to_image(info->mlx, "./images/resized_hero2.xpm", &pixel, &pixel);
}

int main(int argc, char **argv)
{
	t_info *info;

	info = malloc(sizeof(t_info));
	if (info == NULL)
		get_error(ALLOC);
	init_info(info);
	init_map(info, argv[argc - 1]);
	// system("leaks so_long");
	// mlx_hook(info->win, X_EVENT_KEY_RELEASE, 0, );
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &so_long_exit, info);
	mlx_hook(info->win, X_EVENT_KEY_RELEASE, 0, &so_long_key_press, info);
	mlx_loop(info->mlx);
}