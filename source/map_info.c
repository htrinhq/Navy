/*
** EPITECH PROJECT, 2018
** map_info.c
** File description:
** map_info.c
*/

#include "navy.h"

int update_map(char **map, int nbsig1, int nbsig2)
{
	int x = 2 + (nbsig1 * 2);
	int y = 2 + nbsig2;

	if (map[y][x] != '.') {
		map[y][x] = 'x';
		my_printf("%c%d", nbsig1 + 64, nbsig2);
		my_putstr(": hit\n\n");
	} else if (map[y][x] == '.') {
		map[y][x] = 'o';
		my_printf("%c%d", nbsig1 + 64, nbsig2);
		my_putstr(": missed\n\n");
	}
	return (0);
}