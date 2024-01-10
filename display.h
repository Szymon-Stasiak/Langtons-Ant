#pragma once
#include "encoding.h"

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <time.h>

typedef struct Display {
    //Display info
    size_t iteration;
    int fps;

    //Space info
    size_t width;
    size_t heigth;
    wchar_t** space;
    
    //Flags
    int stop;
    int displayInfo;

    //Display output
    FILE* displayOut;
} display_t;


void addRandomBlackSquare(display_t*, double, int , int );
display_t* displayInit(size_t, size_t, double ,int,char *, FILE*);

void printDisplay(display_t*, FILE*);
int displayLoop(display_t*, int, float);

int setGrid(display_t*, int, int, wchar_t);
wchar_t getGrid(display_t*, int, int);

void freeDisplay(display_t*);
