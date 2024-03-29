#include "ant.h"

ant_t* antInit(display_t* dis, int x, int y,char ant_direction) {
    ant_t* ant = malloc(sizeof(ant_t));
    if(!ant) return NULL;
    ant->x = x;
    ant->y = y;
    ant->block = getGrid(dis, x, y);
    if(ant_direction=='T'){
    ant->direction = BOTTOM;
    } else if(ant_direction=='B'){
    ant->direction = TOP;
    } else if (ant_direction=='R'){
    ant->direction = RIGHT;
    } else {
    ant->direction = LEFT;
    }  
    
    if(ant->block == 0) {
        free(ant);
        return NULL;
    }

    setGrid(dis, ant->x, ant->y, *((ant->block == WHITE_SQUARE)? ANT_CHAR_W(ant->direction): ANT_CHAR_B(ant->direction)));

    return ant;
}

void rotateAnt(ant_t* ant, antDirection dir) {
    if(dir == TOP || dir == BOTTOM) return;
    antDirection result = TOP;
    switch (ant->direction)
    {
    case LEFT:
        if(dir == LEFT) result = BOTTOM;
        else result = TOP;
        break;
    
    case RIGHT:
        if(dir == LEFT) result = TOP;
        else result = BOTTOM;
        break;

    case TOP:
        if(dir == LEFT) result = LEFT;
        else result = RIGHT;
        break;

    case BOTTOM:
        if(dir == LEFT) result = RIGHT;
        else result = LEFT;
        break;

    default:
        return;
    }
    ant->direction = result;
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
    rotateAnt(ant, (ch == WHITE_SQUARE)? LEFT : RIGHT);
    setGrid(dis, ant->x, ant->y, *((ant->block == WHITE_SQUARE)? ANT_CHAR_W(ant->direction): ANT_CHAR_B(ant->direction)));
    return 0;
}

void freeAnt(ant_t* ant) {
    free(ant);
}
