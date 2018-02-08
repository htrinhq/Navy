/*
** EPITECH PROJECT, 2018
** map_info.c
** File description:
** map_info.c
*/

#include "navy.h"

int update_player_map(char **map, int *nbsig)
{
	int x = (nbsig[0] * 2);
	int y = 1 + nbsig[1];

	if (map[y][x] != '.' && map[y][x] != 'o') {
		map[y][x] = 'x';
		my_printf("%c%d", nbsig[0] + 64, nbsig[1]);
		my_putstr(": hit\n");
		return (1);
	} else if (map[y][x] == '.' || map[y][x] == 'o') {
		map[y][x] = 'o';
		my_printf("%c%d", nbsig[0] + 64, nbsig[1]);
		my_putstr(": missed\n");
		return (0);
	}
	return (-1);
}

void update_enemy_map(char **map, int *nbsig, int signum)
{
	int x = (nbsig[0] * 2);
	int y = 1 + nbsig[1];

	if (signum == SIGUSR1) {
		map[y][x] = 'x';
		my_printf("%c%d", nbsig[0] + 64, nbsig[1]);
		my_putstr(": hit\n");
	} else if (signum == SIGUSR2) {
		map[y][x] = 'o';
		my_printf("%c%d", nbsig[0] + 64, nbsig[1]);
		my_putstr(": missed\n");
	}
}

int is_map_correct(char *buf)
{
	if (buf[1] != ':' || buf[4] != ':')
		return (84);
	if (buf[2] == buf[5] && (buf[2] > '@' && buf[2] < 'I')) {
		if ((buf[6] - '0') - (buf[3] - '0') != (buf[0] - '0') - 1)
			return (84);
	} else if (buf[3] == buf[6] && (buf[3] > '0' && buf[3] < '9')) {
		if ((buf[5] - '@') - (buf[2] - '@') != (buf[0] - '0') - 1) {
			return (84);
		}
	}
	return (0);
}

int get_player_map(char **map, char *path)
{
	int fd = open(path, O_RDONLY);
	char *buf = malloc(sizeof(char) * 8);
	int i = 0;
	int correct = 0;

	while (i < 4) {
		buf = malloc(sizeof(char) * 8);
		read(fd, buf, 8);
		buf[7] = '\0';
		correct = is_map_correct(buf);
		if (correct == 84) {
			my_printf("incorrect map\n");
			return (84);
		}
		map = set_ships(map, buf);
		i = i + 1;
	}
	return (0);
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
