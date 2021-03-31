/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:03:23 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/31 14:06:07 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_t_parse(t_parse *stock)
{
	static t_map map = (t_map){.close = 0};
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
	return(&stock);
}
