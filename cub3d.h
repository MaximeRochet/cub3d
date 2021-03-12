/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:30:41 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/12 15:21:31 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


typedef struct	s_res
{
	int			x;	
	int			y;
}				t_res;


typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;

}				t_rgb;

typedef struct	s_path
{
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*S;
}				t_path;

typedef struct	s_map
{
	int			close;
	int			user_x;
	int			user_y;
	int			user_deg;
}				t_map;

typedef struct	s_parse
{
	t_res		*res;
	t_rgb		*f;
	t_rgb		*c;
	t_path		*path;
	t_map		*map;
	int			error;
	int			test;
}				t_parse;


size_t		ft_strlen(const char *str);
char		*ft_strfjoin(char *s1, char *s2);
char 		*read_file(char *fichier);
int 		parsing(char *name_file);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif