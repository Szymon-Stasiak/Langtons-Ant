#include "display.h"
#include "encoding.h"
#include "ant.h"

#include <wchar.h>
#include <stdio.h>

int main(int argc, char** argv) {

    UTF_16_SETUP;

    wprintf(L"%lc", ANT_RIGHT);

    /*
    display_t* dis = displayInit(20, 10, 1, stdout);
    dis->displayInfo = 1;

    ant_t* ant = antInit(dis, dis->width/2, dis->heigth/2);

    if(!ant) {
        fwprintf(stderr, L"Error initializing ant\n");
        return -1;
    }

    

    while(displayLoop(dis, 10)) {
        //if(moveAnt(ant, dis)) {
        //    break;
        //}
    }
    freeDisplay(dis);
    freeAnt(ant);
    */
    return 0;
}