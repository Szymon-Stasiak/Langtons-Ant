#include "display.h"
#include "encoding.h"
#include "ant.h"
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <stdio.h>

void print_help(char *program_name) {
    printf("Użycie: %s -r <rows> -c <cols> -i <iterations> -d <direction> \n", program_name);
    printf("Wszystkie oppcje:\n");
    printf("  -r <rows>         Liczba wierszy planszy\n");//works
    printf("  -c <cols>          Liczba kolumn planszy\n");//works
    printf("  -i <iterations>        Liczba iteracji\n");//czasem cos sie wywala za wczesnie nwm czg//tak w okolicy jak zaczyna sie zaptl
    printf("  -d <direction>       Początkowy kierunek mrówki (T,B,R ,L)\n");//works//todo validacja wejscia chcemy tylko TBRL
    printf("  -f <file_name>        Opcjonalne wczytanie mapy z naniesionymi już „czarnymi” polami i aktualną pozycją mrówki\n");//works
    printf("  -p <procent_zapelnienia>    Opcjonalne wygenerowanie mapy z losowo ustawionymi „czarnymi” polami wg procentowego zapełnienia planszy\n");
    printf(" -o <outputNameFile>	Opcjonalne podanie nazwy pliku w ktorym beda wypisywane kolejne iteracje\n");       
    printf(" -s <speed>	Opcjonalne podanie predkosci wypisywania dla 0 wypisanie wszystkich na raz im wartosc jest wieksza tym szybciej sa wypisywane\n");       
    printf(" -x <x>	Pozycja x mrowki\n");       
    printf(" -y <y>	Pozycja y mrowki\n");       
   
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    
    UTF_16_SETUP;

    int rows = 0, cols = 0, iterations = 0;
    char *filename = NULL;
    char *outputFile = NULL;
    char ant_direction = '\0';
    double percentage = -1;
    int speed =0;
    int opt;
    int x= -1;
    int y= -1;
    while ((opt = getopt(argc, argv, "r:c:i:f:d:p:o:s:x:y:")) != -1) {
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
            case 'p':
                percentage = atoi(optarg);
                break;
            case 'o':
                outputFile = optarg;
                break;
            case 's':
            	speed = atoi(optarg);
            	break;
                   case 'x':
            	x = atoi(optarg);
            	break;
                   case 'y':
            	y = atoi(optarg);
            	break;
            default:
                print_help(argv[0]);
        }
    } 
    
    
    if(ant_direction != 'T' && ant_direction != 'B'  &&  ant_direction != 'R' && ant_direction != 'L'){
            fprintf(stderr, "Mozesz uzyc tylko B R albo L do ustalenia kierunku mrowki\n");
            print_help(argv[0]);
    }
   

 
    if (rows <= 0 || cols <= 0 || iterations <= 0 || ant_direction == '\0') {
        fprintf(stderr, "Nie odpowiednia liczba argumentow \n");
        print_help(argv[0]);
    }
    
    display_t* dis = displayInit(cols, rows, percentage, 1,filename , outputFile);
    dis->displayInfo = 1;

    if(x < 0 || x > dis->width-1) {
        x = dis->width/2;
    }

    
    if(y < 0 || y > dis->heigth-1) {
        y = dis->heigth/2;
    }
    ant_t* ant = antInit(dis, x, y, ant_direction);

    if(!ant) {
        fwprintf(stderr, L"Error initializing ant\n");
        return -1;
    }

    while(displayLoop(dis, iterations, speed)) {
       if(moveAnt(ant, dis)) {
           break;
        }
    }
    freeDisplay(dis);
    freeAnt(ant);
    
    return 0;
}
