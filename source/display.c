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

int *display_attack(int *coordinate)
{
	char *cmd;

	my_printf("\nattack: ");
	cmd = input();
	coordinate = char_to_int(cmd);
	my_printf("co1:%d // co2:%d\n", coordinate[0], coordinate[1]);
	send_sig(coordinate[0]);
	usleep(8000);
	send_sig(coordinate[1]);
	my_printf("co1:%d // co2:%d\n", coordinate[0], coordinate[1]);
	return (coordinate);
}

int *display_wait(int *coordinate)
{
	info_t info;

	info = stock_info(NULL, 0);
	coordinate = malloc(sizeof(int) * 2);
	my_printf("\nwaiting for enemy's attack...\n");
	coordinate[0] = get_sig();
	usleep(800);
	coordinate[1] = get_sig();
	kill(info.p2_pid, SIGUSR2);
	return (coordinate);
}