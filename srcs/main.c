/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:23:36 by mrochet           #+#    #+#             */
/*   Updated: 2021/04/08 15:20:28 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	print(void *content)
{
	char *str;

	str = content;
	printf("%s\n", str);
	return (0);
}

int main(int ac, char **av)
{
	(void)ac;

	/*printf("parsing = %d\n", parsing(av[1]));
	
	t_parse stock;
	structure(&stock);
	print_struct(*stock);*/
	
	//first_step_mlx();
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr,1000, 1000 ,"Cub3d");

	mlx_loop(mlx_ptr);
	return(0);
}
