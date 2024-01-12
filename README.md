# Langtons-Ant
## Użycie
  - `-r <rows>`: Określa liczbę wierszy planszy. Działa poprawnie.
  - `-c <cols>`: Określa liczbę kolumn planszy. Działa poprawnie.
  - `-i <iterations>`: Określa liczbę iteracji. Występują problemy czasem, gdy coś się wywala za wcześnie, nie jest jasne dlaczego.
  - `-d <direction>`: Określa początkowy kierunek mrówki (T-góra, B-dół, R-prawo, L-lewo). Działa poprawnie. Zadanie do wykonania: walidacja wejścia, akceptujemy tylko TBRL.
  - `-f <file_name>`: Opcjonalnie wczytuje mapę z naniesionymi już „czarnymi” polami i aktualną pozycją mrówki. Działa poprawnie.
  - `-p <procent_zapelnienia>`: Opcjonalnie generuje mapę z losowo ustawionymi „czarnymi” polami zgodnie z procentowym zapełnieniem planszy.
  - `-o <outputNameFile>`: Opcjonalnie pozwala podać nazwę pliku, w którym będą zapisywane kolejne iteracje.
  - `-s <speed>`: Opcjonalnie umożliwia podanie prędkości wypisywania, gdzie 0 oznacza wypisanie wszystkich iteracji naraz, a większa wartość oznacza szybsze wypisywanie.