/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:03:23 by mrochet           #+#    #+#             */
/*   Updated: 2021/04/22 18:00:23 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	structure(t_parse *stock)
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
