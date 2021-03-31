/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:04:04 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/31 13:47:46 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char *read_file(char *fichier)
{
	int fd;
	char buffer[10];
	char *fc;
	int read_value;

	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		return(0);
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
		return(print_err("Nom du fichier invalide"));	
	}
	return(1);	
}

int print_f_err(char* mssg_err, void *test)
{
	t_parse	*stock;

	if(test)
		free(test);
	stock = structure();
	stock->error = 1;
	printf("Erreur\n%s\n", mssg_err);
	return(0);
}

int print_err(char* mssg_err)
{
	t_parse	*stock;

	stock = structure();
	stock->error = 1;
	printf("Erreur\n%s\n", mssg_err);
	return(0);
}

int parsing(char *name_file)
{
	char 	*file;
	t_parse *stock;

	stock = structure();
	if(!name_file)
		return(print_err("mauvais nombre d'argument"));
	verif_name(name_file, stock);
	file = read_file(name_file);
	if(!file)
		return(0);
	stock->file = file;
	analyse_file(file);
	if(stock->error)
		return(0);
	return(1);

}

int main(int ac, char **av)
{
	(void)ac;

	printf("parsing = %d\n", parsing(av[1]));
	t_parse *stock;
	stock = structure();
	print_struct(*stock);
	return(0);
}
