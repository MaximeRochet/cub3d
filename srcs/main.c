/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:23:36 by mrochet           #+#    #+#             */
/*   Updated: 2021/05/11 16:56:30 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	(void)ac;
	int i = 0;
	t_parse *stock;
	t_recap *recap;
	//	void *mlx_ptr;
	//	void *win_ptr;
	
	if(ac != 2)
		return(print_err("mauvais nombre d'argument", stock));
	stock = calloc(1,sizeof(t_parse));
	recap = calloc(1,sizeof(t_recap));
	if (!stock || !recap)
		return(0);

	init_t_parse(stock);	
	printf("parsing = %d\n", parsing(av[1], stock));
	init_t_recap(recap, stock);
	first_step_mlx(recap);
//	print_recap(*recap);	
//	print_struct(*stock);

//	recap->rays = create_rays(recap);
//	plan_tab(recap);
	return(0);

}

/*
	double rv = 2 * tan(fov * h / (w * 2)) / h;
	double rh = 2 * tan(fov / 2) / w;

	recap.rv = rv;
	recap.rh = rh;
	recap.rays = create_rays(recap);


char	*s;

  char*	s;
  s 0xffff12354;
 *s = 'a';

 char	c;
 c = 'a';

 s = &c;

 int i = 2;
 fonction(&i);
 fonction(void *j)
 */
