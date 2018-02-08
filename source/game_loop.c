/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** game_loop.c
*/

#include "navy.h"

char *input(void)
{
	char *cmd = malloc(sizeof(char) * 2);
	char *final;

	read(0, cmd, 1);
	cmd[1] = '\0';
	final = my_strcat(NULL, cmd);
	while (cmd[0] != '\n') {
		read(0, cmd, 1);
		if (cmd[0] != '\n')
			final = my_strcat(final, cmd);
	}
	return (final);
}

int *char_to_int(char *str)
{
	int *sint = malloc(sizeof(int) * 3);

	sint[0] = str[0] - '@';
	sint[1] = str[1] - '0';
	sint[2] = '\0';
	return (sint);
}

int game_loop(map_t *map, int ac, char **av)
{
	int one_two = -1;

	if (ac != 3)
		one_two = 1;
	connection_check(ac, av);
	while (42) {
		if ((ac == 3 && one_two < 0) || (ac == 2 && one_two > 0))
			display_position(map);
		stock_info(NULL, 1);
		if (one_two > 0)
			display_attack(map);
		if (check_win(one_two, map))
			return (0);
		if (one_two < 0)
			display_wait(map);
		if (check_win(one_two, map))
			return (0);
		one_two = one_two * -1;
	}
}

void connection_check(int ac, char **av)
{
	struct sigaction *sig = malloc(sizeof(struct sigaction));
	info_t info;

	sig->sa_flags = SA_SIGINFO;
	sig->sa_sigaction = my_handler;
	sigaction(SIGUSR1, sig, NULL);
	sigaction(SIGUSR2, sig, NULL);
	my_printf("my_pid: %d\n", getpid());
	if (ac == 2) {
		my_putstr("waiting for enemy connection...");
		pause();
		my_putstr("\n\nenemy connected\n");
		info = stock_info(NULL, 0);
		kill(info.p2_pid, SIGUSR1);
	} else if (ac == 3) {
		if (kill(my_atoi(av[1]), SIGUSR1) == 0)
			my_putstr("successfully connected\n");
	}
}

int check_win(int turn, map_t *map)
{
	int y = 2;
	int count_1 = 0;
	int count_2 = 0;

	while (map->player[y]) {
		count_1 = count_1 + count_in_str(map->player[y], 'x');
		count_2 = count_2 + count_in_str(map->enemy[y], 'x');
		if ((count_1 == 14 || count_2 == 14) && turn > 0) {
			display_position(map);
			my_putstr("\nI won\n");
			return (1);
		}
		if ((count_1 == 14 || count_2 == 14) && turn < 0) {
			display_position(map);
			my_putstr("\nEnemy won\n");
			return (1);
		}
		y = y + 1;
	}
	return (0);
}