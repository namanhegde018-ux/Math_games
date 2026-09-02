//OM

#ifndef MAGIC_BOARD_ARRAY_H
#define MAGIC_BOARD_ARRAY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static inline void set_zero(int n, int (*ptr)[n]) {
    memset(ptr, 0, n*n*sizeof(int));
}

void swap(int *ptr1, int *ptr2);
bool is_magic_square(int n, int (*board)[n]);
void fill_board(int n, int (*ptr)[n]);
void print_board(int n, int (*ptr)[n]);

#endif