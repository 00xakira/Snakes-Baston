#include "lib.h"

int isSurrondedByObstacles(Node *node)
{
    if (node->upNode->snake != nullptr && node->downNode->snake != nullptr && node->leftNode->snake != nullptr && node->rightNode->snake != nullptr)
    {
        return 1;
    }
    return 0;
}

// done sccusefully
int AreThereObstaclesArroundsnake(int row, int col, int board[][WIDTH])
{
    enum whereIssnake where;
    if (row == 0 && col == 0)
    {
        where = upperleft;
    }
    else if (row == 0 && col == 15)
    {
        where = upperright;
    }
    else if (row == 15 && col == 0)
    {
        where = lowerleft;
    }
    else if (row == 15 && col == 15)
    {
        where = lowerright;
    }
    else if (row > 0 && row < 15 && col == 0)
    {
        where = middleleft;
    }
    else if (row > 0 && row < 15 && col == 15)
    {
        where = middleright;
    }
    else if (row == 0 && col > 0 && col < 15)
    {
        where = uppermiddle;
    }
    else if (row == 15 && col > 0 && col < 15)
    {
        where = lowermiddle;
    }
    else if (row > 0 && row < 15 && col > 0 && col < 15)
    {
        where = middle;
    }
    else
    {
        return 0;
    }
    switch (where)
    {
    case upperleft:
        if (board[0][1] % 10 > 0 && board[1][0] % 10 > 0 && board[1][1] % 10 > 0)
        {
            return 1;
        }
        return 0;
    case upperright:
        if (board[0][8] % 10 > 0 && board[1][9] % 10 > 0 && board[1][8] % 10 > 0)
        {
            return 1;
        }
        return 0;
    case lowerleft:
        if (board[8][0] % 10 > 0 && board[9][1] % 10 > 0 && board[8][1] % 10 > 0)
        {
            return 1;
        }
        return 0;
    case lowerright:
        if (board[8][8] % 10 > 0 && board[8][9] % 10 > 0 && board[9][8] % 10 > 0)
        {
            return 1;
        }
        return 0;
    case uppermiddle:
        if (board[row + 1][col] % 10 > 0 && board[row + 1][col + 1] % 10 > 0 && board[row][col + 1] % 10 > 0 && board[row][col - 1] % 10 > 0 && board[row + 1][col - 1] % 10 > 0)
        {
            return 1;
        }
        return 0;
    case lowermiddle:
        if (board[row][col + 1] % 10 > 0 && board[row - 1][col + 1] % 10 > 0 && board[row - 1][col] % 10 > 0 && board[row - 1][col - 1] % 10 > 0 && board[row][col - 1] % 10 > 0)
        {
            return 1;
        }
        return 0;
    case middleleft:
        if (board[row + 1][col] % 10 > 0 && board[row + 1][col + 1] % 10 > 0 && board[row][col + 1] % 10 > 0 && board[row - 1][col + 1] % 10 > 0 && board[row - 1][col] % 10 > 0)
        {
            return 1;
        }
        return 0;
    case middleright:
        if (board[row + 1][col] % 10 > 0 && board[row + 1][col - 1] % 10 > 0 && board[row][col - 1] % 10 > 0 && board[row - 1][col - 1] % 10 > 0 && board[row - 1][col] % 10 > 0)
        {
            return 1;
        }
        return 0;
    case middle:
        if (board[row + 1][col] % 10 > 0 && board[row + 1][col - 1] % 10 > 0 && board[row][col - 1] % 10 > 0 && board[row - 1][col - 1] % 10 > 0 && board[row - 1][col] % 10 > 0 && board[row - 1][col + 1] % 10 > 0 && board[row][col + 1] % 10 > 0 && board[row + 1][col + 1] % 10 > 0)
        {
            return 1;
        }
        return 0;
    }
}

void board()
{

    FILE *file = NULL;
    char *inputpath = argv[2];
    file = fopen(inputpath, "r+");
    fscanf(file, "%d %d", &HEIGHT, &WIDTH); // scan a board array
    int board[HEIGHT][WIDTH];               // make a board array
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            fscanf(file, "%d ", &board[y][x]);
        }
    }
}