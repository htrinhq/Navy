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
	info_t info ;

	info = stock_info(NULL, 0);
	while (i < nb) {
		kill(info.p2_pid, SIGUSR1);
		i = i + 1;
		usleep(8000);
	}
	kill(info.p2_pid, SIGUSR2);
	usleep(100000);
}

int get_sig(void)
{
	int nb = 0;
	info_t info;

	info.signum = 0;
	while (info.signum != SIGUSR2) {
		pause();
		info = stock_info(NULL, 0);
		if (info.signum == SIGUSR1)
			nb = nb + 1;
		else if (info.signum == SIGUSR2)
			return (nb);
		info = stock_info(NULL, 1);
	}
	return (nb);
}

void my_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (signum == SIGUSR1 || signum == SIGUSR2)
		stock_info(siginfo, 0);
}

info_t stock_info(siginfo_t *siginfo, int bo)
{
	static info_t buf;

	if (siginfo != NULL) {
		buf.signum = siginfo->si_signo;
		buf.p2_pid = siginfo->si_pid;
	}
	if (bo == 1)
		buf.signum = 0;
	return (buf);
}