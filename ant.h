#pragma once

#include "encoding.h"
#include "display.h"

#include <wchar.h>
#include <stdio.h>

typedef enum Direction {
    LEFT = -1,
    TOP = 0,
    RIGHT = 1,
    BOTTOM = 2
} antDirection;

#define ANT_CHAR(x) (x == LEFT)? ANT_LEFT : ((x == TOP)? ANT_TOP : ((x == RIGHT)? ANT_RIGHT : ANT_BOTTOM))

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
