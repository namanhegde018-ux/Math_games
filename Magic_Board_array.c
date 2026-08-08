#include <stdio.h>

void fill_board(int n, int (*ptr)[n])
{
    // Edge Cases

    if (n == 0)
    {
        ptr[0][0] = 0;
    }

    else if (n == 1)
    {
        ptr[0][0] = 1;
    }

    // TURAGAGATI Algorithm

    else if (n % 2 != 0)
    {
        int i;
        int mid = n / 2;
        int end = n * n;
        ptr[0][mid] = 1;
        int oldrow, oldcol;
        int rows = 0;
        int columns = mid;
        for (i = 2; i <= end; i++)
        {
            rows += 2;
            columns += 1;
            if (rows >= n)
            {
                rows -= n;
            }
            if (columns >= n)
            {
                columns -= n;
            }
            if (ptr[rows][columns])
            {
                oldrow += 1;
                if (oldrow >= n)
                {
                    oldrow -= n;
                }
                rows = oldrow;
                columns = oldcol;
            }
            ptr[rows][columns] = i;
            oldrow = rows;
            oldcol = columns;
        }
    }

    // SAMPUTAVIDHI Algorithm

    else if ((n % 2 == 0) && (n % 4 == 0))
    {
        int mulapankti[n];
        int gunapankti[n];
        int square = n * n;
        int *start;
        int *end;
        int mid = n / 2;
        int chadya[n][n];
        int chadaka[n][n];
        int rows = 0;
        int columns = 0;
        for (int i = 1; i <= n; i++)
        {
            mulapankti[i - 1] = i;
        }
        start = &mulapankti[mid - 1];
        end = &mulapankti[mid];
        for (columns = 0; columns < n; columns += 2)
        {
            chadya[rows][columns] = *start;
            chadya[rows][columns + 1] = *end;
            chadya[rows + mid][columns] = *end;
            chadya[rows + mid][columns + 1] = *start;
        }
        for (rows = 1; rows < mid; rows++)
        {
            start--;
            end++;
            for (columns = 0; columns < n; columns += 2)
            {
                chadya[rows][columns] = *start;
                chadya[rows][columns + 1] = *end;
                chadya[rows + mid][columns] = *end;
                chadya[rows + mid][columns + 1] = *start;
            }
        }
        int element = 0;
        for (int j = 0; j < square; j += n)
        {
            gunapankti[element] = j;
            element++;
        }
        rows = 0;
        columns = 0;
        start = &gunapankti[0];
        end = &gunapankti[n - 1];
        for (rows = 0; rows < n; rows += 2)
        {
            chadaka[rows][columns] = *start;
            chadaka[rows + 1][columns] = *end;
            chadaka[rows][columns + mid] = *end;
            chadaka[rows + 1][columns + mid] = *start;
        }
        for (columns = 1; columns < mid; columns++)
        {
            start++;
            end--;
            for (rows = 0; rows < n; rows += 2)
            {
                chadaka[rows][columns] = *start;
                chadaka[rows + 1][columns] = *end;
                chadaka[rows][columns + mid] = *end;
                chadaka[rows + 1][columns + mid] = *start;
            }
        }
        rows = 0;
        columns = 0;
        for (rows = 0; rows < n; rows++)
        {
            for (columns = 0; columns < n; columns++)
            {
                ptr[rows][columns] = chadya[rows][columns] + chadaka[(n - 1) - rows][columns];
            }
        }
    }


    
    //

    // else {

    //}
}

void print_board(int n, int (*ptr)[n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    int sum = n * ((n * n) + 1) / 2;
    printf("Sum = %d", sum);
}

int main()
{
    int n;
    while (1)
    {
        printf("Enter the number of rows: ");
        scanf("%d", &n);
        if (n > 0)
        {
            if (n % 2 == 0 && n != 0)
            {
                if (n % 4 != 0)
                {
                    printf("The algorithm is not till found. Please wait: \n");
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("Please Enter POSITIVE integer: \n");
        }
    }

    int end = n * n;
    int magic_board[n][n];
    int (*ptr)[n] = magic_board;
    int *zero_ptr = &magic_board[0][0];
    for (int i = 0; i < end; i++)
    {
        *zero_ptr = 0;
        zero_ptr++;
    }

    fill_board(n, ptr);
    print_board(n, ptr);

    return 0;
}