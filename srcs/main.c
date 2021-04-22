/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:23:36 by mrochet           #+#    #+#             */
/*   Updated: 2021/04/22 15:18:48 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	(void)ac;
	int i = 0;
//	void *mlx_ptr;
//	void *win_ptr;
	t_parse *stock;

	if(ac != 2)
	{
		printf("mauvais nombre d'argument");
		return(0);
	}
	stock = calloc(1,sizeof(t_parse));
	if (!stock)
		return(0);
	structure(stock);	
	print_struct(*stock);
	printf("parsing = %d\n", parsing(av[1], stock));
	print_struct(*stock);
	first_step_mlx(stock);
	return(0);
}

/*char	*s;

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
