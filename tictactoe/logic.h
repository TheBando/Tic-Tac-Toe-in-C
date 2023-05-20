#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define COLOR_WARN "\x1b[33m"
#define COLOR_ERRO "\x1b[31m"
#define COLOR_NORM "\x1b[0m"

static int * board;

void create_board();

int check_move(int, int);

void insert_move(int, int);
int check_by_index(int);
int get_index(int, int);
int check_win();

void clean_logic();


#endif
