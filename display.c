#include "display.h"

display_t* displayInit(size_t width, size_t heigth, int fps, FILE* displayOut) {
    if(fps <= 0) return NULL;

    display_t* display = malloc(sizeof(display_t));
    if(!display) return NULL;

    display->width = width;
    display->heigth = heigth;
    display->fps = fps;
    display->stop = 0;
    display->iteration = 0;
    display->displayInfo = 0;
    display->displayOut = displayOut;

    display->space = malloc(sizeof(wchar_t*) * heigth);
    if(!display->space) {
        free(display);
        return NULL;
    }

    for(int i=0; i<heigth; i++) {
        display->space[i] = malloc(sizeof(wchar_t) * width + 1);
        if(!display->space[i]) {
            free(display->space);
            free(display);
            return NULL;
        }

        for(int j=0; j<width; j++) {
            display->space[i][j] = WHITE_SQUARE;
        }
        display->space[i][width] = L'\0';
    }

    return display;
}


void printDisplay(display_t* dis, FILE* f) {
    fwprintf(f, L"%lc", TOP_LEFT);
    for(int i=0; i<dis->width; i++) {
        fwprintf(f, L"%lc", HORIZONTAL_L);
    }
    fwprintf(f, L"%lc\n", TOP_RIGHT);
    for(int i=0; i<dis->heigth; i++) {
        fwprintf(f, L"%lc%ls%lc\n", VERTICAL_L, dis->space[i], VERTICAL_L);
    }
    fwprintf(f, L"%lc", BOTTOM_LEFT);
    for(int i=0; i<dis->width; i++) {
        fwprintf(f, L"%lc", HORIZONTAL_L);
    }
    fwprintf(f, L"%lc\n", BOTTOM_RIGHT);

    if(dis->displayInfo) {
        fwprintf(f, L"Iteracja ⋙  %d   FPS ⋙  %d\n", dis->iteration, dis->fps);
    }
}

int displayLoop(display_t* dis, int itLimit) {
    if(dis->stop) return 0;
    if((dis->iteration > itLimit && itLimit >= 0) || dis->stop) return 0;

    SCREEN_CLEAR;
    printDisplay(dis, dis->displayOut);
    SLEEP_S(1/dis->fps);

    dis->iteration++;
    return 1;
}

int setGrid(display_t* dis, int x, int y, wchar_t ch) {
    if(x < 0 || y < 0 || x >= dis->width || y >= dis->heigth) return 0;
    dis->space[y][x] = ch;
    return 1;
}

wchar_t getGrid(display_t* dis, int x, int y) {
    if(x < 0 || y < 0 || x >= dis->width || y >= dis->heigth) return 0;
    return dis->space[y][x];
}

void freeDisplay(display_t* dis) {
    for(int i=0; i<dis->heigth; i++) {
        free(dis->space[i]);
    }
    free(dis->space);
    free(dis);
}