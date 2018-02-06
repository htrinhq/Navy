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

void get_player_map(char **map, char *path)
{
	int fd = open(path, O_RDONLY);
	char *buf = malloc(sizeof(char) * 8);
	int i = 0;

	while (i < 4) {
		buf = malloc(sizeof(char) * 8);
		read(fd, buf, 8);
		buf[7] = '\0';
		map = set_ships(map, buf);
		i = i + 1;
	}
}

char **set_ships(char **map, char *buf)
{
	int x = 2 + ((buf[2] - 'A') * 2);
	int y = 2 + (buf[3] - 49);
	int limx = x + ((buf[0] - 48) * 2);
	int limy = y + (buf[0] - 48);

	while (x < limx && limy > y) {
		if (map[y][x])
			map[y][x] = buf[0];
		if (buf[2] - buf[5] != 0)
			x = x + 2;
		else if (buf[3] - buf[6] != 0)
			y = y + 1;
		else
			return (NULL);
	}
	return (map);
}