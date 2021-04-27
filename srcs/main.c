/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:23:36 by mrochet           #+#    #+#             */
/*   Updated: 2021/04/27 16:17:21 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*int main(int ac, char **av)
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
malloc(sizeof(char)*10);
first_step_mlx(stock);
return(0);
}

*/

t_plan *new_plan(int a, int b, int c)
{
	t_plan *plan;

	plan = malloc(sizeof(t_plan));
	plan->a = a;
	plan->b = b;
	plan->c = c;
	plan->d = -(a + b + c);
	return(plan);
}
/*
t_plan new_plan(int a, int b, int c)
{
	t_plan plan;

	plan.a = a;
	plan.b = b;
	plan.c = c;
	plan.d = -(a + b + c);

	return(plan);
}
*/
void print_plan(t_plan *plan)
{
	printf("_________\nplan = >\na = %f\nb = %f\nc = %f\nd = %f\n________\n",plan->a, plan->b, plan->c, plan->d);
}

void print_vect(t_vect vect)
{
	printf("Yah ! 3\n");
	printf("_________\nvecteur= >\na = %f\nb = %f\nc = %f\n________\n",vect.x, vect.y, vect.z);
}

t_vect create_one_ray(int tmp_x, int tmp_y, t_recap recap)
{
	t_vect vect;

	vect.x = (tmp_x - recap.w * 0.5)* recap.rh;
	vect.y = -1;
	vect.z = (recap.h * 0.5 - tmp_y) * recap.rv;

	print_vect(vect);
	printf("Yah !\n");
	return(vect);
}

t_vect **create_rays(t_recap recap)
{
	int tmp_y = -1; 
	int tmp_x = -1;
	t_vect **tab;

	tab = malloc(sizeof(t_vect*)*recap.h);
	while(++tmp_y < recap.h)
	{
		tab[tmp_y] = malloc(sizeof(t_vect)*recap.w);
		while(++tmp_x < recap.w)
		{
			printf("[%d][%d]\n",tmp_y,tmp_x);
			tab[tmp_y][tmp_x] = create_one_ray(tmp_x, tmp_y, recap);
			printf("Yah ! 2\n");
		}
		tmp_x = -1;
		while(++tmp_x < recap.w)
		{
			print_vect(tab[tmp_y][tmp_x]);
		}
		tmp_x = -1;
	}
	
	printf("Yaaaaaaaaaaaaah !\n");
	print_vect(tab[0][0]);
	/*print_vect(tab[9][0]);
	print_vect(tab[0][14]);
	print_vect(tab[9][14]);*/
	 
	return(tab);
}

int main()
{
	//	printf("%lu\n",sizeof(t_vect));
	//	printf("%lu\n",sizeof(double));
	int	w = 15;
	int	h = 10;
	double fov = 1.0472;
	t_recap recap;

	recap.h = h;
	recap.w = w;

	double rv = 2 * tan(fov * h / (w * 2)) / h;
	double rh = 2 * tan(fov / 2) / w;

	recap.rv = rv;
	recap.rh = rh;
	printf("RV = %f\n", recap.rv);
	//printf("RH = %f\n", recap.rh);
	// recap.rays = create_rays(recap);
	
	vect_lst(recap);
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
