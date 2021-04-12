/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fcr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:10:01 by mrochet           #+#    #+#             */
/*   Updated: 2021/04/12 15:01:37 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int verif_r(char *str, t_parse *stock)
{
	char	**tab;
	int i;
	int y;

	i = 0;
	y = -1;
	if(stock->res->x != -1)
		return(print_err("Ligne R multiple", stock));
	tab = ft_split(str, ' ');
	while(tab[++i])
	{
		while(tab[i][++y])
			if(!ft_isdigit(tab[i][y]))
				return(print_err("Element non digit dans F ou C", stock));
		if(i == 3)
			return(print_err("Resolution = 2 chiffres", stock));
	}
	free(tab);
	return(1);

}

void redimention(t_parse *stock, int x, int y)
{
	int size_x;
	int size_y;
	void *mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_get_screen_size(mlx_ptr, &size_x, &size_y);
	if(x > size_x)
		stock->res->x = size_x;
	if(y > size_y)
		stock->res->y = size_y;
	free(mlx_ptr);
}

void	parse_r(char *file_r, t_parse *stock)
{
	char **tab;
	if(!(verif_r(file_r, stock)))
		return;

	tab = ft_split(file_r, 32);

	stock->res->x = ft_atoi(tab[1]);
	stock->res->y = ft_atoi(tab[2]);
	redimention(stock, stock->res->x, stock->res->y);
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
		return(print_err("Ligne F multiple", stock));
	if(str[0] == 'C' && stock->c->r != -1)
		return(print_err("Ligne C multiple", stock));
	while(!ft_isdigit(*str))
		str++;
	tab = ft_split(str, ',');
	while(tab[++i])
	{
		while(tab[i][++y])
			if(!ft_isdigit(tab[i][y]))
				return(print_err("Element non digit dans F ou C", stock));
		y = -1;
		if(!(atoi(tab[i]) < 255 &&  atoi(tab[i]) > 0) || i == 3)
			return(print_err("Couleur = 3 chiffre entre 0 et 255", stock));
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
