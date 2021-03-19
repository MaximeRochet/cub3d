/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:34:30 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/19 12:44:52 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_r(char *file_r, t_parse stock)
{
	int verif;

	verif = 0;
	while (file_r && verif < 2)
	{
		if (*file_r == ' ')
			file_r++;
		else if (ft_atoi(file_r))
		{
			if(verif == 0)
				stock.res->x =  ft_atoi(file_r); 
			if(verif == 1)
				stock.res->y =  ft_atoi(file_r); 
			while(ft_isdigit(*file_r))
				file_r++;
			verif++;
		}
	}
	if((stock.res->x + stock.res->y) > 0 && verif == 2)
		return(stock.nb_parse++);
	return(0);
}

int redirect(char *file)
{
	t_parse stock;
	int num;

	stock = *structure();
	num = stock.nb_parse;
	if(file[0] == 'R' && num == 0 &&parse_r(file, stock))
		return(analyse_file(file));
	/*else if (file[0] == 'N' && num ==1)
		parse_no(file);
	else if (file[0] == 'S' && file[1] == 'O' && num ==2)
		parse_so(file);
	else if (file[0] == 'W' && num ==3)
		parse_we(file);
	else if (file[0] == 'E' && num ==4)
		parse_ea(file);
	else if (file[0] == 'S' && num ==5)
		parse_s(file);
	else if (file[0] == 'F' && num ==6)
		parse_f(file);
	else if (file[0] == 'C' && num ==7)
		parse_c(file);	*/
	else
		return(print_err("Mauvais nombre ou ordre des parametres"));
	return(analyse_file(file));
}

int	 analyse_file(char *file)
{
	char *flag;
	int i;
	int y;

	i = 0;
	y = 0;
	flag = "RNSWESFC";
	while (file[i++] && flag)
		if (file[i] == flag [y])
			{
				if(!(redirect(file + i)))
						return(0);
				y++;
			}
	return(1);
}
