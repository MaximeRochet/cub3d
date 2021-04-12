/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:03:23 by mrochet           #+#    #+#             */
/*   Updated: 2021/04/12 15:26:15 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
void init_t_parse(t_parse *stock)
{
	static t_map map = (t_map){.user_x = 0};
	static t_res res = (t_res){.x = -1};
	static t_path path = (t_path){.NO = 0};
	static t_rgb f = (t_rgb){.r = -1};
	static t_rgb c = (t_rgb){.r = -1};

	stock->map = &map;
	stock->res = &res;
	stock->path = &path;
	stock->f = &f;
	stock->c = &c;
}

t_parse	*structure(void)
{
	static int var = 0;
	static t_parse stock;

	if (!var) {
		var = 1;
		stock = (t_parse){.error = 0};
		init_t_parse(&stock);
	}
	stock.error = 0;
	stock.map.user_x = -1;
	return(&stock);
}

*/


void structure(t_parse *stock)
{
	t_map map;
	stock->map = &map;
	stock->map->user_x = -1;

	t_res res;
	stock->res = &res;
	stock->res->x = -1;

	t_path path;
	stock->path = &path;
	stock->path->NO = NULL;
	stock->path->SO = NULL;
	stock->path->EA = NULL;
	stock->path->WE = NULL;
	stock->path->S = NULL;

	t_rgb f;
	stock->f = &f;
	stock->f->r = -1;
	
	t_rgb c;
	stock->c = &c;
	stock->c->r = -1;

	stock->error = 0;
	//return(stock);
}
