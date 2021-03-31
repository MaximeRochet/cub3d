/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:07:59 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/31 19:06:33 by mrochet          ###   ########lyon.fr   */
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
				stock->map->user_deg = tab[i][y];
			}
			else if(strchr("NSEW", tab[i][y]) && stock->map->user_x != 0)
				return(print_f_err("position multiple", tab));
		}
		y = -1;
	}
	return(1);
}

int close_map(char **tab, int x, int y)
{
	int i;

	i = 0;
	while(tab[i])
		i++;
	if(ft_strchr("NSEW02", tab[y][x]))
	{
		if(y > 0 && y < i -1  && x > 0 && x < ft_strlen(tab[y]) - 1)
		{
			tab[y][x] = '*';
			close_map(tab,x - 1,y);
			close_map(tab,x + 1,y);
			close_map(tab,x,y - 1);
			close_map(tab,x,y + 1);
		}
		else 
			return(print_f_err("map ouverte", tab));
	}	
	else if(tab[y][x] != '1' && tab[y][x] != '*')
		return (print_err("Caractere incorrect dans la map"));
	return(1);
}

int parse_map(char *map)
{
	t_parse *stock;
	char 	**tab;

	stock = structure();
	tab = ft_split(map, '\n');

	if(!find_user(tab, stock))
		return(0);
	if (!stock->map->user_x)	
		return(print_f_err("position du joueur inexistante", tab));
	if (!close_map(tab, stock->map->user_x, stock->map->user_y))
		return(0);
	printf("salut\n");
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
		while(ft_strchr(" \t10", tab[i][y]))
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
		return(0);
	return(1);
}
