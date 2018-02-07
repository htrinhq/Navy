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
	int *coordinate;
	int one_two = -1;

	if (ac != 3)
		one_two = 1;
	connection_check(ac, av);
	while (42) {
		display_position(map);
		if (one_two > 0) {
			coordinate = display_attack(coordinate);
			pause();
		} else {
			coordinate = display_wait(coordinate);
		}
		my_printf("%d // %d\n", coordinate[0], coordinate[1]);
		one_two = one_two * -1;
	}
	return (0);
}

void connection_check(int ac, char **av)
{
	struct sigaction *sig = malloc(sizeof(struct sigaction));

	sig->sa_flags = SA_SIGINFO;
	sig->sa_sigaction = my_handler;
	sigaction(SIGUSR1, sig, NULL);
	sigaction(SIGUSR2, sig, NULL);
	my_printf("my_pid: %d\n", getpid());
	if (ac == 2) {
		my_putstr("waiting for enemy connection...");
		pause();
		my_putstr("\n\nenemy connected\n\n");
	} else if (ac == 3) {
		if (kill(my_atoi(av[1]), SIGUSR1) == 0)
			my_putstr("successfully connected\n\n");
	}
}
