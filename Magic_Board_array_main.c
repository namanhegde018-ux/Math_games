#include <stdio.h>
#include <string.h>
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
        else
        {
            printf("Please Enter a POSITIVE Number or Number OTHER THAN 2. \n\n");
        }
    }

    int magic_board[n][n];
    int (*ptr)[n] = magic_board;
    set_zero(n, ptr);

    fill_board(n, ptr);
    print_board(n, ptr);

    return 0;
}