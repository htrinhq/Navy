/*
** EPITECH PROJECT, 2018
** send_and_get_sig.c
** File description:
** send_and_get_sig.c
*/

#include "navy.h"

void send_sig(int nb)
{
	int i = 0;

	while (i < nb) {
		kill(glob.p2_pid, SIGUSR1);
		i = i + 1;
	}
	kill(glob.p2_pid, SIGUSR2);
}

int get_sig(void)
{
	int nb = 1;

	while (nb != 0) {
		signal(SIGUSR1, my_handler2);
		signal(SIGUSR2, my_handler2);
		nb = glob.i;
	}
	return (nb);
}

void my_handler2(int signo)
{
	if (signo == SIGUSR2)
		glob.i = 0;
	if (signo == SIGUSR1)
		glob.i = glob.i + 1;
}