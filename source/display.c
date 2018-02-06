/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display.c
*/

#include "navy.h"

void display_position(map_t *map)
{
	my_printf("my positions:\n");
	display_tab(map->player);
	my_printf("\nenemy's positions:\n");
	display_tab(map->enemy);
}

void display_attack(int *coordinate)
{
	char *cmd;

	my_printf("\nattack: ");
	cmd = input();
	coordinate = char_to_int(cmd);
	send_sig(coordinate[0]);
	send_sig(coordinate[1]);
}

int *display_wait(int *coordinate)
{
	coordinate = malloc(sizeof(int) * 2);
	my_printf("\nwaiting for enemy's attack...\n");
	coordinate[0] = get_sig();
	coordinate[1] = get_sig();
	kill(glob.p2_pid, SIGUSR2);
	return (coordinate);
}