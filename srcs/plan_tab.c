/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:12:27 by mrochet           #+#    #+#             */
/*   Updated: 2021/05/06 18:17:56 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_plan *new_plan(int a, int b, int c, int d)
{
	t_plan *plan;

	plan = ft_calloc(1, sizeof(t_plan));
	plan->a = a;
	plan->b = b;
	plan->c = c;
	plan->d = -d;
	return(plan);
}

t_plan **create_tab_plan(int i)
{
	t_plan **plan;
	plan = ft_calloc(i + 1 ,sizeof(t_plan *));
	return(plan);
}

/*  void fill_tab_plan(char **map,int x, int y, t_recap *recap, int lon)
	{ 
	if (x != 0 && map[y][x-1]) 
	if(map[y][x-1] != '1')
	{
	recap->plan_est[x] = new_plan(1,0,0,x);
	dprintf(1,"1\n");
	}
	if (x < ft_strlen(map[y]) - 1 && map[y][x+1])	
	if (map[y][x+1] != '1')
	{
	recap->plan_west[x] = new_plan(1,0,0,x);
	dprintf(1,"2\n");
	}
	if()
	if ()
	{
	recap->plan_south[y] = new_plan(0,1,0,y);
	dprintf(1,"3\n");
	}
	if (y !=0 && map[y-1][x])
	if (map[y-1][x] != '1')
	{
	recap->plan_north[y] = new_plan(0,1,0,y);
	dprintf(1,"4\n");
	}
	}

	void fill_tab_plan(char **map,int x, int y, t_recap *recap, int lon)
	{ 
	if (x != 0 && map[y][x-1])    
	if(map[y][x-1] != '1')
	{
	recap->plan_est[x] = new_plan(1,0,0,x);
	dprintf(1,"1\n");
	}
	if (x < ft_strlen(map[y]) - 1 && map[y][x+1])	
	if (map[y][x+1] != '1')
	{
	recap->plan_west[x] = new_plan(1,0,0,x);
	dprintf(1,"2\n");
	}
	if()
	if ()
	{
	recap->plan_south[y] = new_plan(0,1,0,y);
	dprintf(1,"3\n");
	}
	if (y !=0 && map[y-1][x])
	if (map[y-1][x] != '1')
	{
	recap->plan_north[y] = new_plan(0,1,0,y);
	dprintf(1,"4\n");
	}
	}
	void analyse_tab_plan(char **map,int lon, int lar, t_recap *recap)
	{
	int x;
	int y;

	x = -1;
	y = -1;
	recap->plan_north = create_tab_plan(lon);
	recap->plan_south = create_tab_plan(lon);
	recap->plan_west = create_tab_plan(lar);
	recap->plan_est = create_tab_plan(lar);
//print_recap(*recap);
printf("lar = %d long = %d\n", lar, lon);
while (++x < 5)
printf("%s\n", map[x]);
while(++y <= lon)
{
	while(++x < ft_strlen(map[y]))
	{
		printf("x = %d y = %d carac = %c\n", x, y, map[y][x]);
		if(x != 0)
			printf("x = %d y = %d carac-1 = %c\n", x, y, map[y][x-1]);
		if(map[y][x] == '1')
			fill_tab_plan(map, x, y, recap, lon);
	}
	x = -1;
}
print_tab_plan(recap->plan_est, 4, "est");
print_tab_plan(recap->plan_west, 4, "west");
print_tab_plan(recap->plan_north, 4,"north");
print_tab_plan(recap->plan_south, 4, "south");

}
*/

void	fill_tab_plan(char **map,int x, int y, t_recap *recap, char c) 
{
	if(c == 'E')
	{
		recap->plan_est[x] = new_plan(1,0,0,x);
		dprintf(1,"1\n");
	}
	if (c == 'W')
	{
		recap->plan_west[x] = new_plan(1,0,0,x);
		dprintf(1,"2\n");
	}
	if(c == 'S')
	{
		recap->plan_south[y] = new_plan(0,1,0,y);
		dprintf(1,"3\n");
	}
	if (c == 'N')
	{
		recap->plan_north[y] = new_plan(0,1,0,y);
		dprintf(1,"4\n");
	}

}

void	find_plan(char **tab, int x, int y, t_recap *recap, char c)
{
	int	i;
	
	printf("YA x=%d y=%d c=%c c_tab=%c \n", x, y, c, tab[y][x]);
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	if (ft_strchr("NSEW02", tab[y][x]))
	{
		if (y > 0 && y < i - 1 && x > 0 && x < ft_strlen(tab[y]) - 1)
		{
			printf("YA2 %d %d %c\n", x, y, c);
			dprintf(1, "netwhat\n\n");
			tab[y][x] = '*';
			find_plan(tab, x - 1, y, recap, 'W');
			find_plan(tab, x + 1, y, recap, 'E');
			find_plan(tab, x, y - 1, recap, 'S');
			find_plan(tab, x, y + 1, recap, 'N');
		}
	}
	else if (tab[y][x] == '1')
	{
		dprintf(1,"fill\n\n");
		fill_tab_plan(tab, x, y, recap,c);
	}
}

void plan_tab(t_recap *recap)
{
	char **tab;
	int lon;
	int lar;

	lar = 0;
	lon = -1;
	tab = ft_split(recap->map, '\n');
	while(tab[++lon])
	{
		if(ft_strlen(tab[lon]) > lar)
			lar = ft_strlen(tab[lon]);
	}
	printf("%d %d\n", lon,lar);
	recap->plan_north = create_tab_plan(lon);
	recap->plan_south = create_tab_plan(lon);
	recap->plan_west = create_tab_plan(lar);
	recap->plan_est = create_tab_plan(lar);
	
	//analyse_tab_plan(tab, recap);
	printf("%d %d \n%s\n", recap->map_info.user_x,recap->map_info.user_y, (*recap).map);
	find_plan(tab, recap->map_info.user_x, recap->map_info.user_y, recap,'O');
	print_tab_plan(recap->plan_est, 4, "est");
	print_tab_plan(recap->plan_west, 4, "west");
	print_tab_plan(recap->plan_north, 4,"north");
	print_tab_plan(recap->plan_south, 4, "south");
}
