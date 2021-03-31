/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:07:59 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/31 13:57:20 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int find_user(char **tab, t_parse *stock)
{
	int i;
	int y;

	i = -1;
	y = -1;
	while(tab[++i])
	{
		while(tab[i][++y])
		{
			if(!strchr("012 NSEW", tab[i][y]))
				return(print_f_err("caractere invalid dans la map", tab));
			if(strchr("NSEW", tab[i][y]) && stock->map->user_x == 0)
			{
				stock->map->user_x = y;
				stock->map->user_y = i;
			}
			else if(strchr("NSEW", tab[i][y]) && stock->map->user_x != 0)
				return(print_f_err("position multiple", tab));
		}
		y = -1;
	}
	print_struct(*stock);
	return(1);
}

int close_map(char **tab, t_parse *stock)
{
	return(0);
}

int parse_map(char *map)
{
	t_parse *stock;
	char 	**tab;

	stock = structure();
	tab = ft_split(map, '\n');
	if(!find_user(tab, stock))
		return(0);
	if (!close_map(tab, stock))
		return(0);
	//verif caractere "012NSEW"
	//recup coordonne et orientation joueurn
	//feelflood remplace "0 2NSEW"
	return(1);
}

int find_map(char *file)
{
	int i;
	int y;
	char **tab;

	i = -1;
	y = 0;
	tab = ft_split(file, '\n');
	while(tab[++i])
	{
		while(ft_strchr(" \t1", tab[i][y]))
		{
			if(!tab[i][y])
			{
				free(tab);
				return(i);
			}
			y++;
		}
		y = 0;
	}
	free(tab);
	return(print_err("Map incorrect ou inexistante"));
}


int init_map(char *file, t_parse *stock)
{
	int i;
	int n;
	int nb_ligne;

	i = 0;
	n = 0;
	nb_ligne = find_map(file);
	if(stock->ind != 521)
		return(print_err("Informations manquantes"));
	while(file[i] &&  n < nb_ligne)
	{

		if(file[i] == '\n' && file[i + 1] != '\n')
			n++;
		i++;
	}
	stock->file_map = file + i;
	i = -1;
	while(stock->file_map[++i])
		if(stock->file_map[i] == '\n' && stock->file_map[i + 1] == '\n')
			return(print_err("Ligne vide dans la map"));
	if(!parse_map(stock->file_map))
		return(print_err("Map invalid"));
	return(1);
}
