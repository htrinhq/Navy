/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** game_loop.c
*/

#include "navy.h"

int game_loop(map_t *map, int ac, char **av)
{
	int one_two = -1;
	int ret = 0;

	if (ac == 2)
		one_two = 1;
	if (connection_check(ac, av))
		return (84);
	while (42) {
		ret = game(one_two, map, ac);
		if (ret == 0)
			return (0);
		one_two = one_two * -1;
	}
}

int connection_check(int ac, char **av)
{
	struct sigaction *sig = malloc(sizeof(struct sigaction));

	sig->sa_flags = SA_SIGINFO;
	sig->sa_sigaction = my_handler;
	sigaction(SIGUSR1, sig, NULL);
	sigaction(SIGUSR2, sig, NULL);
	my_printf("my_pid: %d\n", getpid());
	if (ac == 2) {
		display_p1();
	} else if (ac == 3) {
		if (kill(my_atoi(av[1]), SIGUSR1) == 0)
			my_putstr("successfully connected\n");
		else {
			my_puterr("unable to connect to host\n");
			return (1);
		}
	}
	return (0);
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

int game(int one_two, map_t *map, int ac)
{
	int ret = 1;

	if ((ac == 3 && one_two < 0) || (ac == 2 && one_two > 0))
		display_position(map);
	stock_info(NULL, 1);
	if (one_two > 0)
		ret = display_attack(map);
	if (ret == 0)
		return (0);
	if (check_win(one_two, map))
		return (0);
	if (one_two < 0)
		display_wait(map);
	if (check_win(one_two, map))
		return (0);
	return (1);
}