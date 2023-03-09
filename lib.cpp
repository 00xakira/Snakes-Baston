#include "lib.h"

int isSurrondedByObstacles(Node *node)
{
    if (node->upNode->snake != nullptr && node->downNode->snake != nullptr && node->leftNode->snake != nullptr && node->rightNode->snake != nullptr)
    {
        return 1;
    }
    return 0;
}

void exportBoard(Node *startNode)
{
    Node *currentNode = startNode;
    char outputPath[32] = "output.txt";
    FILE *file = NULL;
    file = fopen(outputPath, "rw+");

    while (currentNode->vCorner != lowerCorner || currentNode->hCorner != rightCorner)
    {
        while (currentNode->hCorner != rightCorner)
        {

            fprintf(file, "%c ", getExportSymbol(currentNode));
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

char getExportSymbol(Node *node)
{

    if (node->snake)
    {
        if (node->snake == node->upNode->snake)
        {
            return 'U';
        }
        else if (node->snake == node->downNode->snake)
        {
            return 'D';
        }
        else if (node->snake == node->leftNode->snake)
        {
            return 'L';
        }
        else if (node->snake == node->rightNode->snake)
        {
            return 'R';
        }
    }

    if (node->wormhole)
    {
        return '*';
    }

    return node->weight - '0';
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