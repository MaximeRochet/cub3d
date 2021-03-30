/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:34:30 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/26 18:47:10 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int verif_r(char *str, t_parse *stock)
{
	char	**tab;
	int i;
	int y;

	i = 0;
	y = -1;
	if(stock->res->x != -1)	
		return(print_err("Ligne R multiple"));
	tab = ft_split(str, ' ');
	while(tab[++i])
	{
		while(tab[i][++y])
			if(!ft_isdigit(tab[i][y]))
				return(print_err("Element non digit dans F ou C"));
		//verif taille ecran
		if(i == 3)
			return(print_err("Resolution = 2 chiffres"));
	}
	free(tab);
	return(1);

}

void	parse_r(char *file_r, t_parse *stock)
{
	char **tab;
	if(!(verif_r(file_r, stock)))
		return;

	tab = ft_split(file_r, 32);

	stock->res->x = ft_atoi(tab[1]);
	stock->res->y = ft_atoi(tab[2]);	
	stock->ind += 1;
	free(tab);
}

int verif_fc(char* str, t_parse *stock)
{
	char	**tab;
	int i;
	int y;

	i = -1;
	y = -1;
	if(str[0] == 'F' && stock->f->r != -1)	
		return(print_err("Ligne F multiple"));
	if(str[0] == 'C' && stock->c->r != -1)	
		return(print_err("Ligne C multiple"));
	while(!ft_isdigit(*str))
		str++;
	tab = ft_split(str, ',');
	while(tab[++i])
	{
		while(tab[i][++y])
			if(!ft_isdigit(tab[i][y]))
				return(print_err("Element non digit dans F ou C"));
		y = -1;
		if(!(atoi(tab[i]) < 255 &&  atoi(tab[i]) > 0) || i == 3)
			return(print_err("Couleur = 3 chiffre entre 0 et 255 "));
	}
	free(tab);
	return(1);
}

void	parse_fc(char *file_fc, t_parse *stock)
{

 	char	**tab;
	char	c;

	if(!(verif_fc(file_fc, stock)))
		return;
	c = file_fc[0];
	while(!ft_isdigit(*file_fc))
		file_fc++;
	tab = ft_split(file_fc, ',');
	if(c == 'F')
	{
		stock->f->r = ft_atoi(tab[0]);	
		stock->f->g = ft_atoi(tab[1]);
		stock->f->b = ft_atoi(tab[2]);	
	}
	if(c == 'C')
	{
		stock->c->r = ft_atoi(tab[0]);	
		stock->c->g = ft_atoi(tab[1]);
		stock->c->b = ft_atoi(tab[2]);	
	}
	stock->ind += 10;
	free(tab);
}

char * verif_path(char *str, t_parse *stock)
{
	char *charset;
	int fd;

	charset = "NSOWEA ";
	while(ft_strchr(charset, *str))
		str++;
	//a decommenter quand les fichier seront valides
	/*fd = open(str, O_RDONLY);
	if(fd == -1)
		return(print_err("Un chemin est incorrect"));
	close(fd);*/
	return(str);
}

void parse_path(char *file_path, t_parse *stock)
{
		char *path;

		path = verif_path(file_path, stock);
		if(!path)
			return;
		if(file_path[0] == 'N' && stock->path->NO == NULL)
			stock->path->NO = path;
		if(file_path[0] == 'S' && file_path[1] == 'O' && stock->path->SO == NULL)
			stock->path->SO = path;
		if(file_path[0] == 'W' && stock->path->WE == NULL)
			stock->path->WE = path;
		if(file_path[0] == 'E' && stock->path->EA == NULL)
			stock->path->EA = path;
		if(file_path[0] == 'S' && stock->path->S == NULL)
			stock->path->S = path;
		stock->ind += 100;

}

void redirect(char *file)
{
	t_parse *stock;
	char *charset;

	charset = "SNWE";
	stock = structure();
	if(file[0] == 'R')
		parse_r(file, stock);
	else if (ft_strchr(charset, file[0]))
		parse_path(file, stock);
	else if (file[0] == 'F')
		
parse_fc(file, stock);
	else if (file[0] == 'C')
		parse_fc(file, stock);
}

int find_user(char *map)
{
	char **tab;
	int i;
	int y;

	i = -1;
	y = -1;
	tab = ft_split(map, '\n');
	while(tab[++i])
	{
		while(tab[i][++y])
		{
			if(!strchr("012 NSEW", map[i][y]))
				return(print_f_err("caractere invalid dans la map", stock));
			if(strchr("NSEW", map[i][y]) && stock->map->x == NULL)
			{
				stock->map->x = y;
				stock->map->y = i;
			}
			if(strchr("NSEW", map[i][y]) && stock->map->x != NULL)	
				return(print__f_err("position multiple", stock));
		}
		y = 0;	
	}
}

int parse_map(char *map)
{
	if(!find_user(map))
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

int	 analyse_file(char *file)
{
	char *charset;
	char **tab;
	int i;
	int y;
	t_parse *stock;

	stock = structure();
	i = -1;
	y = 0;
	tab = ft_split(file, 10);
	while(tab[++i])
	{
		y=0;
		while(tab[i][y] <= 32)
			y++;
		if(strchr("RNSWESFC", tab[i][y]))
			redirect(tab[i] + y);
		else if(tab[i][y] != '\n' && tab[i][y] != '1')
			return(print_err("Ligne incorrect dans le .cub"));
		if(stock->error == 1)
			return(0);
	}
	free(tab);
	return(init_map(file, stock));
}
