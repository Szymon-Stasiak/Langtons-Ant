#pragma once

#include "encoding.h"
#include "display.h"

#include <wchar.h>
#include <stdio.h>

typedef enum Direction {
    LEFT,
    TOP,
    RIGHT,
    BOTTOM
} antDirection;

#define ANT_CHAR_W(x) (x == LEFT)? ANT_LEFT : ((x == TOP)? ANT_TOP : ((x == RIGHT)? ANT_RIGHT : ANT_BOTTOM))
#define ANT_CHAR_B(x) (x == LEFT)? ANT_LEFT_B : ((x == TOP)? ANT_TOP_B : ((x == RIGHT)? ANT_RIGHT_B : ANT_BOTTOM_B))

typedef struct Ant{
    int x;
    int y;
    
    antDirection direction;
    wchar_t block;
} ant_t;

ant_t* antInit(display_t*, int, int,char);
void rotateAnt(ant_t*, antDirection);
int moveAnt(ant_t*, display_t*);

void freeAnt(ant_t*);
