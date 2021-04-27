/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_cub3d.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:46:25 by mrochet           #+#    #+#             */
/*   Updated: 2021/04/27 16:16:52 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSEF_H
# define OSEF_H

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

typedef	struct	s_recap
{
	int h;
	int w;
	float rv;
	float rh;
	t_vect **rays;
}				t_recap;


void	first_step_mlx(t_parse *stock);
t_vect **create_rays(t_recap recap);
t_vect create_one_ray(int tmp_x, int tmp_y, t_recap recap);
void print_plan(t_plan *plan);
t_plan *new_plan(int a, int b, int c);
void vect_lst(t_recap recap);

#endif
