/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:46:25 by mrochet           #+#    #+#             */
/*   Updated: 2021/05/05 13:54:31 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSEF_H
# define OSEF_H
# define fov 1.0472

typedef	struct	s_plan
{
	float	a;
	float	b;
	float	c;
	float	d;
}				t_plan;

typedef	struct	s_vect
{
	double	x;
	double	y;
	double	z;
}				t_vect;

typedef	struct	s_sprite
{
	float a;
	float b;
	float c;
	float d;
}				t_sprite;

typedef	struct	s_recap
{
	int h;
	int w;
	char *map;
	double rv;
	double rh;
	void *mlx_ptr;
	void *mlx_win;
	t_map	map_info;
	t_plan **plan_north; 
	t_plan **plan_south; 
	t_plan **plan_west; 
	t_plan **plan_est; 
	t_vect **rays;
}				t_recap;

t_vect	**create_rays(t_recap *recap);
t_vect	create_one_ray(int tmp_x, int tmp_y, t_recap *recap);
t_plan	*new_plan(int a, int b, int c, int d);
void	print_recap(t_recap recap);
void 	print_tab_plan(t_plan **plan, int lon, char *def);
void	plan_tab(t_recap *recap);
void	print_plan(t_plan *plan);
void	print_vect(t_vect vect);
void	first_step_mlx(t_parse *stock);
void	init_t_recap(t_recap *recap, t_parse *stock);
void	find_plan(char **tab, int x, int y, t_recap *recap, char c);
void 	plan_tab(t_recap *recap);


#endif
