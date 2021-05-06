/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:19:26 by mrochet           #+#    #+#             */
/*   Updated: 2021/05/03 15:22:53 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_vect create_one_ray(int tmp_x, int tmp_y, t_recap *recap)
{
	t_vect vect;

	vect.x = (tmp_x - recap->w * 0.5)* recap->rh;
	vect.y = -1;
	vect.z = (recap->h * 0.5 - tmp_y) * recap->rv;

//	print_vect(vect);
	return(vect);
}

t_vect **create_rays(t_recap *recap)
{
	int tmp_y = -1;
	int tmp_x = -1;
	t_vect **tab;

	tab = malloc(sizeof(t_vect*)*recap->h);
	while(++tmp_y < recap->h)
	{
		tab[tmp_y] = malloc(sizeof(t_vect)*recap->w);
		while(++tmp_x < recap->w)
		{
			tab[tmp_y][tmp_x] = create_one_ray(tmp_x, tmp_y, recap);
		}
		tmp_x = -1;
	}

	print_vect(tab[0][0]);
	print_vect(tab[recap->h-1][0]);
	print_vect(tab[0][recap->w-1]);
	print_vect(tab[recap->h-1][recap->w-1]);

	return(tab);
}
