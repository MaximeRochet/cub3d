/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:30:41 by mrochet           #+#    #+#             */
/*   Updated: 2021/03/31 16:14:53 by mrochet          ###   ########lyon.fr   */
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
# include "../utils/libft.h"

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
	char		*file;
	char		*file_map;
	int			ind;
}				t_parse;


size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strfjoin(char *s1, char *s2);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);


t_parse		*structure(void);
void		print_struct(t_parse stock);
char 		*read_file(char *fichier);
int 		parsing(char *name_file);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			analyse_file(char *file);
int 		verif_name(char *namefile, t_parse *stock);
int 		print_err(char* mssg_err);
int 		print_f_err(char* mssg_err, void *test);

int			verif_r(char *str, t_parse *stock);
void		parse_r(char *file_r, t_parse *stock);
int			verif_fc(char* str, t_parse *stock);
void		parse_fc(char *file_fc, t_parse *stock);
void		parse_path(char *file_path, t_parse *stock);
char		*verif_path(char *str, t_parse *stock);
void		redirect(char *file, t_parse *stock);

int			init_map(char *file, t_parse *stock);
int			find_map(char *file);
int			parse_map(char *map);
int			find_user(char **tab, t_parse *stock);
#endif
