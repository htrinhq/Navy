/*
** EPITECH PROJECT, 2017
** navy.h
** File description:
** navy.h
*/

#ifndef	NAVY_H
#define	NAVY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "str.h"
#include "stdyo.h"

typedef struct info_sig {
	int p2_pid;
	int signum;
} info_t;

typedef struct map {
	char **player;
	char **enemy;
} map_t;

int check_option(int ac, char **av);
void display_help(void);
int get_player_map(char **map, char *path);
char **set_ships(char **map, char *buf);
char **fill_first_lines(char **player, int x, char letter);
void fill_other_lines(int *x, char **player, int y);
char **fill_map(char **player);
void display_tab(char **tab);
int game_loop(map_t *map, int ac, char **av);
void my_handler(int signum, siginfo_t *siginfo, void *context);
int fill_struct(map_t *map, int ac, char **av);
int connection_check(int ac, char **av);
void display_position(map_t *map);
void display_attack(map_t *map);
void display_wait(map_t *map);
void send_sig(int nb);
int get_sig(void);
char *input(void);
int *char_to_int(char *str);
info_t stock_info(siginfo_t *siginfo, int bo);
int update_player_map(char **map, int *nbsig);
void update_enemy_map(char **map, int *nbsig, int signum);
int check_cmd(char *str);
int count_in_str(char *str, char c);
int check_win(int turn, map_t *map);
void display_p1(void);

#endif
