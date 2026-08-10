#ifndef MAGIC_BOARD_ARRAY_H
#define MAGIC_BOARD_ARRAY_H

#include <stdio.h>
#include <string.h>

static inline void set_zero(int n, int (*ptr)[n]) {
    memset(ptr, 0, n*n*sizeof(int));
}

void fill_board(int n, int (*ptr)[n]);
void print_board(int n, int (*ptr)[n]);

#endif