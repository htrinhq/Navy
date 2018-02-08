/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** display.c
*/

#include "navy.h"

void display_position(map_t *map)
{
	my_putchar('\n');
	my_printf("my positions:\n");
	display_tab(map->player);
	my_printf("\nenemy's positions:\n");
	display_tab(map->enemy);
}

void display_attack(map_t *map)
{
	int *coordinate;
	char *cmd;
	info_t info;
	int bo = 0;

	my_printf("\nattack: ");
	cmd = input();
	bo = check_cmd(cmd);
	while (bo == 0) {
		my_printf("attack: ");
		cmd = input();
		bo = check_cmd(cmd);
	}
	coordinate = char_to_int(cmd);
	send_sig(coordinate[0]);
	usleep(8000);
	send_sig(coordinate[1]);
	info = stock_info(NULL, 0);
	update_enemy_map(map->enemy, coordinate, info.signum);
	usleep(8000);
}

void display_wait(map_t *map)
{
	info_t info;
	int *coordinate;

	info = stock_info(NULL, 0);
	coordinate = malloc(sizeof(int) * 2);
	my_printf("\nwaiting for enemy's attack...\n");
	coordinate[0] = get_sig();
	usleep(800);
	coordinate[1] = get_sig();
	usleep(15000);
	if (update_player_map(map->player, coordinate))
		kill(info.p2_pid, SIGUSR1);
	else
		kill(info.p2_pid, SIGUSR2);
	usleep(8000);
}

int check_cmd(char *str)
{
	if (my_strlen(str) > 2) {
		my_putstr("wrong position\n");
		return (0);
	}
	if (str[0] > 'H' || str[0] < 'A') {
		my_putstr("wrong position\n");
		return (0);
	}
	if (str[1] < '1' || str[1] > '8') {
		my_putstr("wrong position\n");
		return (0);
	}
	return (1);
}

int count_in_str(char *str, char c)
{
	int i = 0;
	int nb = 0;

	while (i <= 16) {
		if (str[i] == c)
			nb = nb + 1;
		i = i + 1;
	}
	return (nb);
}