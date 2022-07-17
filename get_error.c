/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:12:25 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/18 00:12:41 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_error(int e)
{
	if (e == ALLOC)
		printf("Error\n: allocation fail\n");
	else if (e == NOARG)
		printf("Error\n: there is no filename(.ber)\n");
	else if (e == OTHER)
		printf("Error\n: developer's error situation\n");
	else if (e == MAPERROR)
		printf("Error\n: map error\n");
	exit(EXIT_FAILURE);
}
