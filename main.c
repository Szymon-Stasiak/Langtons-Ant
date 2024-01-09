#include "display.h"
#include "encoding.h"
#include "ant.h"
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <stdio.h>

void print_help(char *program_name) {
    printf("Użycie: %s -m <liczba_wierszy> -n <liczba_kolumn> -i <liczba_iteracji> -f <nazwa_plikow> -d <kierunek_mrowki>\n", program_name);
    printf("Opcje:\n");
    printf("  -r <liczba_wierszy>         Liczba wierszy planszy\n");//works
    printf("  -c <liczba_kolumn>          Liczba kolumn planszy\n");//works
    printf("  -i <liczba_iteracji>        Liczba iteracji\n");//czasem cos sie wywala za wczesnie nwm czg//tak w okolicy jak zaczyna sie zaptl
    printf("  -f <nazwa_plikow>           wczytanie podanej nazywy pilku\n"); //works
    printf("  -d <kierunek_mrowki>        Początkowy kierunek mrówki (T,B,R ,L)\n");//works//todo validacja wejscia chcemy tylko TBRL
    printf("  -m <sciezka_do_mapy>        Opcjonalne wczytanie mapy z naniesionymi już „czarnymi” polami i aktualną pozycją mrówki\n");//works
    printf("  -p <procent_zapelnienia>    Opcjonalne wygenerowanie mapy z losowo ustawionymi „czarnymi” polami wg procentowego zapełnienia planszy\n");//works
    printf(" -o <outputNameFile>\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int rows = 0, cols = 0, iterations = 0;
    char *filename = NULL;
    char *outputFile = NULL;
    char ant_direction = '\0';
    char *map_path = NULL;
    double percentage = -1;
    int opt;
    while ((opt = getopt(argc, argv, "r:c:i:f:d:m:p:o:")) != -1) {
        switch (opt) {
		case 'r':
                rows = atoi(optarg);
                break;
            case 'c':
                cols = atoi(optarg);
                break;
            case 'i':
                iterations = atoi(optarg);
                break;
            case 'f':
                filename= optarg;
                break;
	    case 'd':
                ant_direction = optarg[0];
                break;
            case 'm':
                map_path = optarg;
                break;
            case 'p':
                percentage = atoi(optarg);
                break;
            case 'o':
                outputFile = optarg;
                break;
            default:
                print_help(argv[0]);
        }
    }

 
    if (rows <= 0 || cols <= 0 || iterations <= 0 || ant_direction == '\0') {
        fprintf(stderr, "Not enough data \n");
        print_help(argv[0]);
    }


    UTF_16_SETUP;

    wprintf(L"%lc", ANT_RIGHT);
   
    
    display_t* dis = displayInit(cols, rows, percentage, 1,filename , stdout);
    dis->displayInfo = 1;

    ant_t* ant = antInit(dis, dis->width/2, dis->heigth/2, ant_direction);

    if(!ant) {
        fwprintf(stderr, L"Error initializing ant\n");
        return -1;
    }

    

    while(displayLoop(dis, iterations)) {
       if(moveAnt(ant, dis)) {
           break;
        }
    }
    freeDisplay(dis);
    freeAnt(ant);
    
    return 0;
}
