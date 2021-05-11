/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premier_pas_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:21:57 by mrochet           #+#    #+#             */
/*   Updated: 2021/05/11 18:08:13 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void redimention(t_recap *recap)
{
	int size_x;
	int size_y;

	mlx_get_screen_size(recap->mlx_ptr, &size_x, &size_y);
	if(recap->w > size_x)
		recap->w = size_x;
	if(recap->h > size_y)
		recap->h = size_y;
}

void    new_image(t_recap *recap)
{
    int     endian;
    int     bit;
    endian = 0;
    bit = 0;
    recap->mlx_img = mlx_new_image(recap->mlx_ptr, recap->w, recap->h);
    recap->data = (int *)mlx_get_data_addr(recap->mlx_img, &bit, &recap->w, \
			&endian); // cast en int sinon char pete
    recap->w /= 4;
}

void first_step_mlx(t_recap *recap)
{
	
	recap->mlx_ptr = mlx_init();
	redimention(recap);
	recap->win_ptr = mlx_new_window(recap->mlx_ptr, recap->w, \
			recap->h, "Cub3d");
	new_image(recap);
	print_recap(*recap);
	//mlx_loop(recap->mlx_ptr);
}
