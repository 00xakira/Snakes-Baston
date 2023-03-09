#include <fstream>
#include <iostream>
using namespace std;

enum VerticalCorner
{
    noCorner = 0,
    upperCorner = 1,
    lowerCorner = 2
};

enum HorizontalCorner
{
    noCorner = 0,
    leftCorner = 1,
    rightCorner = 2
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
    int weight;
    HorizontalCorner vCorner;
    VerticalCorner hCorner;
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

char getExportSymbol(Node *node);

void exportBoard(Node *startNode);