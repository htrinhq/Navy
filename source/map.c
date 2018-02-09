/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** map creation functions
*/

#include "navy.h"

char **fill_first_lines(char **player, int x, char letter)
{
	player = malloc(sizeof(char*) * 11);
	player[0] = malloc(sizeof(char) * 18);
	player[1] = malloc(sizeof(char) * 18);
	player[0][0] = ' ';
	player[0][1] = '|';
	while (x < 17) {
		if (x % 2 == 0) {
			player[0][x] = letter;
			letter = letter + 1;
		} else
			player[0][x] = ' ';
		x = x + 1;
	}
	player[0][17] = '\0';
	player[1][0] = '-';
	player[1][1] = '+';
	for (x = 2; x < 17; x = x + 1)
		player[1][x] = '-';
	player[1][17] = '\0';
	return (player);
}

void fill_other_lines(int *x, char **player, int y)
{
	while(*x < 17) {
		if (*x % 2 == 0)
			player[y][*x] = '.';
		else
			player[y][*x] = ' ';
		*x = *x + 1;
	}
}

char **fill_map(char **player)
{
	int y = 2;
	int x = 2;
	char nb = '1';

	player = malloc(sizeof(char*) * 11);
	player = fill_first_lines(player, 2, 'A');
	player[y] = malloc(sizeof(char) * 18);
	while (y < 10) {
		player[y][0] = nb;
		nb = nb + 1;
		player[y][1] = '|';
		fill_other_lines(&x, player, y);
		player[y][x] = '\0';
		x = 2;
		y = y + 1;
		player[y] = malloc(sizeof(char) * 18);
	}
	player[y] = NULL;
	return (player);
}

int fill_struct(map_t *map, int ac, char **av)
{
	int error = 0;

	map->player = fill_map(map->player);
	map->enemy = fill_map(map->enemy);
	if (ac == 2) {
		error = get_player_map(map->player, av[1]);
		if (error)
			return (error);
	}
	if (ac == 3) {
		get_player_map(map->player, av[2]);
		if (error)
			return (error);
	}
	return (0);
}
