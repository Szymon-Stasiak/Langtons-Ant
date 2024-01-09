#pragma once

#ifdef _WIN32
    #include <Windows.h>
    #include <io.h>
    #include <fcntl.h>

    #define UTF_16_SETUP _setmode(_fileno(stdout), _O_U16TEXT)
    #define SCREEN_CLEAR system("cls")

    #define SLEEP_S(x) Sleep((x) * 1000)
#else
    #include <unistd.h>
    #include <locale.h>

    #define UTF_16_SETUP setlocale(LC_ALL, "")
    #define SCREEN_CLEAR system("clear")

    #define SLEEP_S(x) sleep(x)
#endif

//Space chars unicode codes
#define WHITE_SQUARE L'\u2588'    // █
#define BLACK_SQUARE L' '         //  

//Frame chars unicode codes
#define TOP_LEFT L'\u2554'        // ╔
#define TOP_RIGHT L'\u2557'       // ╗
#define HORIZONTAL_L L'\u2550'    // ═
#define VERTICAL_L L'\u2551'      // ║
#define BOTTOM_LEFT L'\u255A'     // ╚
#define BOTTOM_RIGHT L'\u255D'    // ╝

//Ant chars unicode codes
#define ANT_LEFT L"◀"
#define ANT_TOP L"▼"
#define ANT_RIGHT L"▶"
#define ANT_BOTTOM L"▲"
   
#define ANT_TOP_B L"▽"
#define ANT_RIGHT_B L"▷"
#define ANT_LEFT_B L"◁"
#define ANT_BOTTOM_B L"△"