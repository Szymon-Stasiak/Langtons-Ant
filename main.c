#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_help(char *program_name) {
    printf("Użycie: %s -m <liczba_wierszy> -n <liczba_kolumn> -i <liczba_iteracji> -f <nazwa_plikow> -d <kierunek_mrowki>\n", program_name);
    printf("Opcje:\n");
    printf("  -r <liczba_wierszy>         Liczba wierszy planszy\n");
    printf("  -c <liczba_kolumn>          Liczba kolumn planszy\n");
    printf("  -i <liczba_iteracji>        Liczba iteracji\n");
    printf("  -f <nazwa_plikow>           Przedrostek plików wynikowych\n");
    printf("  -d <kierunek_mrowki>        Początkowy kierunek mrówki (U,D,R ,L)\n");
    printf("  -m <sciezka_do_mapy>        Opcjonalne wczytanie mapy z naniesionymi już „czarnymi” polami i aktualną pozycją mrówki\n");
    printf("  -p <procent_zapelnienia>    Opcjonalne wygenerowanie mapy z losowo ustawionymi „czarnymi” polami wg procentowego zapełnienia planszy\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int rows = 0, cols = 0, iterations = 0;
    char *file_prefix = NULL;
    char ant_direction = '\0';
    char *map_path = NULL;
    int random_fill_percentage = -1;
    int opt;
    while ((opt = getopt(argc, argv, "r:c:i:f:d:m:p:")) != -1) {
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
                file_prefix = optarg;
                break;
	    case 'd':
                ant_direction = optarg[0];
                break;
            case 'm':
                map_path = optarg;
                break;
            case 'p':
                random_fill_percentage = atoi(optarg);
                break;
            default:
                print_help(argv[0]);
        }
    }

 
    if (rows <= 0 || cols <= 0 || iterations <= 0 || ant_direction == '\0') {
        fprintf(stderr, "Not enough data \n");
        print_help(argv[0]);
    }

 
    return 0;
}

