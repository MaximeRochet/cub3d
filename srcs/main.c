/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:23:36 by mrochet           #+#    #+#             */
/*   Updated: 2021/04/12 15:27:55 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	(void)ac;
	int i = 0;
	

	t_parse *stock;
	stock = calloc(1,sizeof(t_parse));
	//printf("debut %p\n", stock);
	structure(stock);
	//printf("apres init %p\n", stock);

	printf("[main]\t res.x = %d\t add.res.x = %p\t add.stock = %p\n", stock->res->x, &stock->res->x, &stock);
	printf("[main]\t res.x = %d\t add.res.x = %p\t add.stock = %p\n", stock->res->x, &stock->res->x, &stock);

	printf("parsing = %d\n", parsing(av[1], stock));
	
	//print_struct(*stock);
	
	//first_step_mlx();
	//void *mlx_ptr;
	//void *win_ptr;

	//mlx_ptr = mlx_init();
	//win_ptr = mlx_new_window(mlx_ptr,1000, 1000 ,"Cub3d");

	//mlx_loop(mlx_ptr);*/
	return(0);
}
