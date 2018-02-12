/*
** EPITECH PROJECT, 2018
** user.c
** File description:
** user.c
*/

#include "navy.h"

char *input(void)
{
	char *cmd = malloc(sizeof(char) * 2);
	char *final;

	read(0, cmd, 1);
	if (cmd[0] == '\0')
		return (NULL);
	cmd[1] = '\0';
	final = my_strcat(NULL, cmd);
	while (cmd[0] != '\n') {
		read(0, cmd, 1);
		if (cmd[0] == '\0')
			return (NULL);
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