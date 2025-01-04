#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <HashMap.c>

#define r 8
#define c 8

int **intialBoard();
void print(int **board);
void freeBoard(int **board);
void fillBoard(int **board);

/*
king = K
q = Q
bishop = B
knight = N
rook = R
pawns = P
*/

int main()
{
    int **board = intialBoard();

    fillBoard(board);
    print(board);
    freeBoard(board);
}

int **intialBoard()
{
    int *values = calloc(r * c, sizeof(int));
    int **rows = malloc(r * sizeof(int *));
    for (int i = 0; i < r; ++i)
    {
        rows[i] = values + i * c;
    }
    return rows;
}

void freeBoard(int **board)
{
    free(board[0]); // Free the contiguous block
    free(board);    // Free the row pointers
}

void print(int **board)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", board[i][j]);
        }

        printf("\n");
    }
}

void fillBoard(int **board)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0)
            {
                switch (j)
                {
                case 0:
                    board[i][j] = 27;
                    break;
                case 1:
                    board[i][j] = 25;
                    break;
                case 2:
                    board[i][j] = 23;
                    break;
                case 3:
                    board[i][j] = 22;
                    break;
                case 4:
                    board[i][j] = 21;
                    break;
                case 5:
                    board[i][j] = 24;
                    break;
                case 6:
                    board[i][j] = 26;
                    break;
                case 7:
                    board[i][j] = 28;
                    break;
                default:
                    break;
                }
            }
            else if (i == 1)
            {
                board[i][j] = 41 + j;
            }
            else if (i == 6)
            {
                board[i][j] = 31 + j;
            }
            else if (i == 7)
            {
                switch (j)
                {
                case 0:
                    board[i][j] = 17;
                    break;
                case 1:
                    board[i][j] = 15;
                    break;
                case 2:
                    board[i][j] = 13;
                    break;
                case 3:
                    board[i][j] = 12;
                    break;
                case 4:
                    board[i][j] = 11;
                    break;
                case 5:
                    board[i][j] = 14;
                    break;
                case 6:
                    board[i][j] = 16;
                    break;
                case 7:
                    board[i][j] = 18;
                    break;
                default:
                    break;
                }
            }
        }
    }
}
