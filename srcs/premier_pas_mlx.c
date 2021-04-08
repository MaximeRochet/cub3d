/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premier_pas_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:21:57 by mrochet           #+#    #+#             */
/*   Updated: 2021/04/08 14:34:37 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//# include "../minilibx_mms_20200219/mlx.h"
#include "../includes/cub3d.h"

void first_step_mlx()
{
	void *mlx_ptr;
	void *win_ptr;
/*	int i;
	int y;
	int size_x;
	int size_y;*/


	/*t_parse *stock;
	stock = structure();
*/
/*	i = 0;
	y = 0;
	*/
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr,1000, 1000 ,"Cub3d");
	/*while(i++ < 500)
	{
		while (y++ < 500)
			if (y % 5 && y % 4)
				mlx_pixel_put(mlx_ptr, win_ptr, i, y, 0xFFFFFF);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, i, y, 0x000000);
		y=0;

	}
	while(i++ < 1000)
	{
		while (y++ < 500)
			mlx_pixel_put(mlx_ptr, win_ptr, i, y, 0x3409A3);
		y=0;
	}*/
	printf("test1\n");
	mlx_loop(mlx_ptr);

	printf("test2\n");
}
