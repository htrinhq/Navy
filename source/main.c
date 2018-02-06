/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main for navy
*/

#include "navy.h"

int main(int ac, char **av)
{
	map_t *map = malloc(sizeof(map_t));
	int ret = 0;

	ret = check_option(ac, av);
	fill_struct(map, ac, av);
	if (ret == 1)
		return (0);
	if (ret == 84)
		return (84);
	ret = game_loop(map, ac, av);
	return (ret);
}

void fill_struct(map_t *map, int ac, char **av)
{
	map->player = fill_map(map->player);
	map->enemy = fill_map(map->enemy);
	if (ac == 2)
		get_player_map(map->player, av[1]);
	if (ac == 3)
		get_player_map(map->player, av[2]);
}