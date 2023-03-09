#include <fstream>
#include <iostream>
using namespace std;

enum whereIssnake
{
    upperleft,
    upperright,
    lowerleft,
    lowerright,
    uppermiddle,
    lowermiddle,
    middleright,
    middleleft,
    middle,
};

typedef struct _wormhole
{
    Node *startNode;
    Node *endNode;
} Wormhole;

typedef struct _snake
{
    Node *head;
    Node *tail;
} Snake;

typedef struct _node
{
    char verticalCorner;
    char horizontalCorner;
    struct _node *upNode;
    struct _node *downNode;
    struct _node *leftNode;
    struct _node *rightNode;
    Snake *snake;
    Wormhole *wormhole;
} Node;

int HEIGHT;
int WIDTH;

void check_cell();

void display_board();

void snake_movement();

int isSurrondedByObstacles(Node *node);

int AreThereObstaclesArroundsnake(int row, int col, int board[][WIDTH]);