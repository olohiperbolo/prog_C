#include <stdio.h>

int main() {

    int tablica[10];

    for(int i =0; i < 10; i++){
        tablica[i] = i;
    }

    int *wskaznik = &tablica[1];

    for(int i = 0; i < 10; i++){
        printf("%i\n", *wskaznik);
        wskaznik++;
    }


    return 0;
}
