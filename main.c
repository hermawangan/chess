#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define r 8
#define c 8

int **intialBoard();
void print(int **board);
void freeBoard(int **board);
void fillBoard(int **board);

struct pieces
{
    char king[1][3];
    char queen[1][3];
    char bishops[2][5];
    char rooks[2][5];
    char knights[2][5];
    char pawns[8][17];
};

/*
king = K
q = Q
bishop = B
knight = N
rook = R
pawns = P

white K = 11
white Q = 12
white B1 = 13
white B2 = 14
white N1 = 15
white N2 = 16
white R1 = 17
white R2 = 18
white p1 = 31
white p2 = 32
white p3 = 33
white p4 = 34
white p5 = 35
white p6 = 36
white p7 = 37
white p8 = 38

black K = 21
black Q = 22
black B1 = 23
black B2 = 24
black N1 = 25
black N2 = 26
black R1 = 27
black R2 = 28
black p1 = 41
black p2 = 42
black p3 = 43
black p4 = 44
black p5 = 45
black p6 = 46
black p7 = 47
black p8 = 48
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
