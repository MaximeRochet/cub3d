/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:04:04 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/12 16:19:29 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//map, carac autorise 012NSEW
//entouree de 1
//indication separee d une ou plusieurs \no

t_parse	*structure(void)
{
	static t_parse	stock = (t_parse){.error = 0};
	t_map map = (t_map){.close = 0};
	t_res res = (t_res){.x = 0};
	t_path path = (t_path){.NO = 0};
	t_rgb f = (t_rgb){.r = 0};
	t_rgb c = (t_rgb){.r = 0};
	stock.map = &map;
	stock.res = &res;
	stock.path = &path;
	stock.f = &f;
	stock.c = &c;
	return(&stock);
}

char *read_file(char *fichier)
{
	int fd;
	char buffer[10];
	char *fc;
	char *tmp_fc;
	int read_value;

	fd = open(fichier, O_RDONLY);
	fc = NULL;	
	while(((read_value = read(fd, buffer, 9)) !=  0))
	{
		buffer[read_value] = '\0';
		fc = ft_strfjoin(fc, buffer);
	}
	close (fd);
	return(fc);
}

int verif_name(char *namefile, t_parse *stock)
{
	int size;

	size = ft_strlen(namefile);
	if (ft_strncmp((namefile + (size - 4)), ".cub", 5))
	{
		stock->error = 1;
		printf("file name invalid\n");
		return(0);
	}
	return(1);
	
}

int print_err(char* mssg_err)
{
	t_parse	stock;

	stock = *structure();
	stock.error = 1;
	printf("Erreur = %s\n", mssg_err);
	return(0);
}

int parsing(char *name_file)
{
	char 	*file;
	int 	i;
	t_parse stock;

	stock = *structure();
	if(!name_file)
		return(print_err("mauvais nombre d'argument"));
	verif_name(name_file, &stock);
	file = read_file(name_file);
	if (stock.error)
		return(0);
	return(1);
}

int main(int ac, char **av)
{
	printf("parsing = %d\n", parsing(av[1]));
	return(0);	
}