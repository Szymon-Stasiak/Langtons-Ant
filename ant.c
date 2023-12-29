#include "ant.h"

ant_t* antInit(display_t* dis, int x, int y) {
    ant_t* ant = malloc(sizeof(ant_t));
    if(!ant) return NULL;
    ant->x = x;
    ant->y = y;
    ant->block = getGrid(dis, x, y);
    ant->direction = TOP;
    if(ant->block == 0) {
        free(ant);
        return NULL;
    }

    return ant;
}

void rotateAnt(ant_t* ant, antDirection dir) {
    if(dir == TOP || dir == BOTTOM) return;
    ant->direction = (antDirection)(((int)ant->direction + 1 + (int)dir)%4 - 1);
}

int moveAnt(ant_t* ant, display_t* dis) {
    if(ant->block == WHITE_SQUARE) ant->block = BLACK_SQUARE;
    else ant->block = WHITE_SQUARE;

    setGrid(dis, ant->x, ant->y, ant->block);
    switch(ant->direction) {
        case LEFT:
            ant->x--;
            break;
        case RIGHT:
            ant->x++;
            break;
        case TOP:
            ant->y++;
            break;
        case BOTTOM:
            ant->y--;
            break;
        default:
        return -1;
    }
    wchar_t ch;
    if((ch = getGrid(dis, ant->x, ant->y)) == 0) return -1;
    ant->block = ch;
    rotateAnt(ant, (ch == WHITE_SQUARE)? RIGHT : LEFT);
    setGrid(dis, ant->x, ant->y, *(ANT_CHAR(ant->direction)));
    return 0;
}

void freeAnt(ant_t* ant) {
    free(ant);
}