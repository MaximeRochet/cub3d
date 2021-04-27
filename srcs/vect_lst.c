/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:12:27 by mrochet           #+#    #+#             */
/*   Updated: 2021/04/27 16:53:56 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



void vect_lst(t_recap recap)
{
	t_plan *plan;
	t_plan *plan2;
	t_list *plan_north;
	t_list **pn;

	plan = malloc(sizeof(t_plan));
	printf("%lu\n", sizeof(t_plan));
	plan = new_plan(1,2,3);
	print_plan(plan);

	plan_north = ft_lstnew(plan);
	plan2 = new_plan(4,5,6);

	*pn = plan_north;
	//ft_lstadd_back(pn, ft_lstnew(plan2));

}
