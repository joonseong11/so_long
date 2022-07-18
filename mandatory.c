/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:59:54 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/18 14:00:26 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	so_long_key_press(int keycode, void *info)
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

int	main(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (info == NULL)
		get_error(ALLOC);
	init_map(info, argv[argc - 1]);
	mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, &so_long_exit, info);
	mlx_hook(info->win, X_EVENT_KEY_RELEASE, 0, &so_long_key_press, info);
	mlx_loop(info->mlx);
}
