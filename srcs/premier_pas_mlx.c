/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premier_pas_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:21:57 by mrochet           #+#    #+#             */
/*   Updated: 2021/04/22 17:56:36 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//# include "../minilibx_mms_20200219/mlx.h"
#include "../includes/cub3d.h"

void redimention(t_parse *stock, void *mlx_ptr)
{
	int size_x;
	int size_y;

	mlx_get_screen_size(mlx_ptr, &size_x, &size_y);
	if(stock->res.x > size_x)
		stock->res.x = size_x;
	if(stock->res.y > size_y)
		stock->res.y = size_y;
}

void first_step_mlx(t_parse *stock)
{
	void *mlx_ptr;
	void *win_ptr;
	
	mlx_ptr = mlx_init();
	redimention(stock, mlx_ptr);
	win_ptr = mlx_new_window(mlx_ptr, stock->res.x, stock->res.y,"Cub3d");
	mlx_loop(mlx_ptr);
}
