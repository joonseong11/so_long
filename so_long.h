/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:30:15 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/18 01:09:25 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#define BUFFER_SIZE 1042
#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

typedef enum e_enum
{
	ALLOC = 0,
	NOARG,
	MAPERROR,
	OTHER
}	t_enum;

typedef struct s_img
{
	void	*coin;
	void	*hero;
	void	*tile;
	void	*wall;
	void	*door;
}	t_img;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_img	*img;
	char	*str_map;
	int		wid;
	int		hei;
	int		coin_on_map;
	int		step;
}	t_info;

/*
*							BASIC FUNC						*
*/
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
/*
*							mandatory func						*
*/
void	init_map(t_info *info, char *filename);
void	check_map_component(t_info *info);
void	check_map_rectagular(t_info *info);
void	check_map_close(t_info *info);
void	adapt_image(t_info *info);
void	get_error(int e);
int		so_long_exit(void);
void	move_hero_w(t_info *info);
void	move_hero_s(t_info *info);
void	move_hero_a(t_info *info);
void	move_hero_d(t_info *info);


#endif