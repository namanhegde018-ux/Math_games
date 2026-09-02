// OM

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Magic_Board_array.h"

int main()
{
    int n;
    while (1)
    {
        printf("Enter the number of rows: ");
        scanf("%d", &n);
        if ((n > 0) && (n != 2))
        {
            break;
        }
        else if (n == 2)
        {
            printf("2X2 magic board CANNOT be constructed\n\n");
        }
        else
        {
            printf("Enter NON-ZERO POSITIVE number\n\n");
        }
    }

    int (*magic_board)[n] = malloc(n * sizeof *magic_board);
    if (magic_board == NULL)
    {
        return 1;
    }
    set_zero(n, magic_board);

    fill_board(n, magic_board);
    print_board(n, magic_board);
    printf("Is Magic Board: %d\n\n", is_magic_square(n, magic_board));

    free(magic_board);

    return 0;
}