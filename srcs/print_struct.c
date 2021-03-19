#include "cub3d.h"

void print_struct(t_parse stock)
{
	printf("\n");
	printf("|_________________________|\n");
	printf("|       __STOCK__         |\n");
	printf("| error = %d\n", stock.error);
	printf("| file  = %s \n", stock.file);
	printf("| nb parse = %d \n", stock.nb_parse);
	printf("| \n");

	printf("|        __RES__          |\n");
	printf("| x  = %d \n", stock.res->x);
	printf("| y  = %d \n", stock.res->y);
	printf("| \n");

	printf("|        __F__            |\n");
	printf("| r  = %d \n", stock.f->r);
	printf("| g  = %d \n", stock.f->g);
	printf("| b  = %d \n", stock.f->b);
	printf("| \n");

	printf("|         __C__           |\n");
	printf("| r  = %d \n", stock.c->r);
	printf("| g  = %d \n", stock.c->g);
	printf("| b  = %d \n", stock.c->b);
	printf("| \n");

	printf("|        __PATH__         |\n");
	printf("| NO = %s \n", stock.path->NO);
	printf("| SO = %s \n", stock.path->NO);
	printf("| WE = %s \n", stock.path->NO);
	printf("| EA = %s \n", stock.path->NO);
	printf("| S = %s \n", stock.path->NO);
	printf("| \n");

	printf("|        __MAP__          |\n");
	printf("| close  = %d \n", stock.map->close);
	printf("| user_x  = %d \n", stock.map->close);
	printf("| user_y  = %d \n", stock.map->close);
	printf("| user_deg = %d \n", stock.map->close);	
	printf("|_________________________|\n");

}
