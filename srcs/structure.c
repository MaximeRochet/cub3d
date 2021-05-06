/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:03:23 by mrochet           #+#    #+#             */
/*   Updated: 2021/05/05 12:02:31 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_t_parse(t_parse *stock)
{
	stock->map.user_x = -1;
	stock->res.x = -1;
	stock->path.NO = NULL;
	stock->path.SO = NULL;
	stock->path.EA = NULL;
	stock->path.WE = NULL;
	stock->path.S = NULL;
	stock->f.r = -1;
	stock->c.r = -1;
	stock->error = 0;
}

void	init_t_recap(t_recap *recap, t_parse *stock)
{
//	print_struct(*stock);
	recap->h = stock->res.y;
	recap->w = stock->res.x;
	recap->map_info = stock->map;
	recap->rv = 2 * tan(fov * stock->res.y / (stock->res.x * 2)) / stock->res.y;
	recap->rh = 2 * tan(fov / 2) / stock->res.x;
	recap->map = stock->file_map;
}
