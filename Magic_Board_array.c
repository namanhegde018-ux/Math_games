// OM

#include "Magic_Board_array.h"

void fill_board(int n, int (*ptr)[n])
{
    // Edge Cases

    if (n == 1)
    {
        ptr[0][0] = 1;
    }

    else if (n == 2) {
        printf("No Magic Square exists\n");
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

    else if (n % 4 == 0)
    {
        int *mulapankti = malloc(n * sizeof(int));
        int *gunapankti = malloc(n * sizeof(int));

        if (mulapankti == NULL || gunapankti == NULL)
        {
            free(mulapankti);
            free(gunapankti);
            return;
        }
        int square = n * n;
        int *start;
        int *end;
        int mid = n / 2;
        int (*chadya)[n] = malloc(n * sizeof *chadya);
        int (*chadaka)[n] = malloc(n * sizeof *chadaka);

        if (chadya == NULL || chadaka == NULL)
        {
            free(chadya);
            free(chadaka);
            free(mulapankti);
            free(gunapankti);
            return;
        }
        int rows = 0;
        int columns = 0;
        for (int i = 1; i <= n; i++)
        {
            mulapankti[i - 1] = i;
        }
        start = mulapankti + (mid - 1);
        end = mulapankti + (mid);
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
        start = gunapankti;
        end = gunapankti + (n - 1);
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

        free(chadya);
        free(chadaka);
        free(mulapankti);
        free(gunapankti);
    }

    // VISHAMAGARBHA SUTRA

    else
    {
        int rows;
        int cols;
        int square = n * n;
        int num = 1;
        int i;
        int shlishta = (n / 2) - 2;
        int pita;
        for (rows = 0; rows < n; rows++)
        {
            for (cols = 0; cols < n; cols++)
            {
                ptr[rows][cols] = num;
                num++;
            }
        }
        int *ptr1 = &ptr[0][0];
        int *ptr2 = &ptr[n - 1][n - 1];
        int temp;
        // for main diagonal
        for (i = 0; i < (n / 2); i++)
        {
            ptr1 = &ptr[i][i];
            ptr2 = &ptr[n - 1 - i][n - 1 - i];
            temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = temp;
        }

        // for another diagonal
        for (i = 0; i < (n / 2); i++)
        {
            ptr1 = &ptr[i][n - 1 - i];
            ptr2 = &ptr[n - 1 - i][i];
            temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = temp;
        }

        ptr1 = &ptr[(n / 2) - 1][n - 1];
        ptr2 = &ptr[n / 2][n - 1];
        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;

        int flag = 0;
        int k = 1;
        pita = shlishta - 1;
        while (pita != 0)
        {
            if (!flag)
            {
                ptr1 = &ptr[(n / 2) - 1][k];
                ptr2 = &ptr[n / 2][k];
                temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;
                pita -= 1;
                flag = 1;
            }
            else
            {
                ptr1 = &ptr[(n / 2) - 1][n - 1 - k];
                ptr2 = &ptr[n / 2][n - 1 - k];
                temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;
                pita -= 1;
                flag = 0;
                k += 1;
            }
        }

        int count;
        int column = 0;
        int row = 0;
        // row exchange
        for (i = 0; i < ((n / 2) - 1); i++)
        {
            count = shlishta;
            column = i;
            while (count != 0)
            {
                if ((i + column + 1) != (n - 1))
                {
                    ptr1 = &ptr[i][column + 1];
                    ptr2 = &ptr[n - 1 - i][column + 1];
                    temp = *ptr1;
                    *ptr1 = *ptr2;
                    *ptr2 = temp;
                    column++;
                    count--;
                }
                else
                {
                    column++;
                }
            }
        }

        // column exchange
        flag = 0;
        int columnsum;
        int sum = (n * ((n * n) + 1)) / 2;
        int shortage;
        int fill;
        for (i = 0; i < (n / 2); i++)
        {
            pita = shlishta;
            columnsum = 0;
            for (int j = 0; j < n; j++)
            {
                columnsum += ptr[j][i];
            }
            row = 0;
            shortage = sum - columnsum;
            fill = shortage / shlishta;
            while ((!flag) && (pita))
            {
                if (row == i) {
                    row++;
                    flag = 1;
                    break;
                }
                ptr1 = &ptr[row][i];
                ptr2 = &ptr[n - 1 - row][n - 1 - i];
                if ((*ptr2) - (*ptr1) == fill)
                {
                    temp = *ptr1;
                    *ptr1 = *ptr2;
                    *ptr2 = temp;
                    ptr1 = &ptr[n - 1 - row][i];
                    ptr2 = &ptr[row][n - 1 - i];
                    temp = *ptr1;
                    *ptr1 = *ptr2;
                    *ptr2 = temp;
                    pita -= 2;
                }
                row++;
            }

            while (flag && pita) {
                if (row == (n - 1 - i)) {
                    flag = 0;
                    row++;
                    break;
                }
                ptr1 = &ptr[row][i];
                ptr2 = &ptr[row][n - 1 - i];
                if ((*ptr2) - (*ptr1) == (shortage / shlishta))
                {
                    temp = *ptr1;
                    *ptr1 = *ptr2;
                    *ptr2 = temp;
                    pita -= 1;
                }
                row++;
            }
        }
        
    }
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
    printf("Sum = %d\n\n", sum);
}