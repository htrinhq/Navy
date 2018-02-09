/*
** EPITECH PROJECT, 2018
** error_handling.c
** File description:
** error_handling.c
*/

#include "navy.h"

int check_option(int ac, char **av)
{
	if (!av[1]) {
		my_puterr(
		"Invalid number of arguments, rerun with -h for help.\n");
		return (84);
	}
	if (my_strcmp(av[1], "-h")) {
		display_help();
		return (1);
	}
	if (ac < 2 || ac > 3) {
		my_puterr(
		"Invalid number of arguments, rerun with -h for help.\n");
		return (84);
	}
	if ((ac == 2 && open(av[1], O_RDONLY) == -1) ||
	(ac == 3 && open(av[2], O_RDONLY) == -1)) {
		my_puterr("Could not read the file.\n");
		return (84);
	}
	return (0);
}

void display_help(void)
{
	my_putstr("USAGE\n\t\t./navy [first_player_pid] navy_positions\n\n");
	my_putstr("DESCRIPTION\n\t\t1st_player_pid\t");
	my_putstr("only for the 2nd player.\tpid of the 1st player.\n\t\t");
	my_putstr("navy_positions\t");
	my_putstr("file representing the positions of the ships.\n");
}

void display_p1(void)
{
	info_t info;

	my_putstr("waiting for enemy connection...");
	pause();
	my_putstr("\n\nenemy connected\n");
	info = stock_info(NULL, 0);
	kill(info.p2_pid, SIGUSR1);
}