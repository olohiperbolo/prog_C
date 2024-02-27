#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//zad6
char*wykonaj_ruch(int ruch){
    switch(ruch){
        case 0:
            return "papier";
        case 1:
            return "kamien";
        case 2:
            return "nozyce";
        default:
            return "bledny ruch";
    }
}
char*ruch_komputera(){
    srand(time(NULL));
    int losowa = rand() % 3;
    if(losowa == 0){
        return "papier";
    }
    else if(losowa == 1){
        return "kamien";
    }
    else{
        return "nozyce";
    }
}
//tworzenie tablicy do odczytu ruchow
void scores(int *ruchy_gracza, char **ruchy_komputera, int liczba_rund,int *punkty_komputera, int *punkty_gracza){
    printf("Historia ruchow:\n");
    for(int i = 0; i < liczba_rund; i++){
        printf("Runda %d: Gracz wybral %s, Komputer wybral %s, Wynik %d : %d\n", i+1, wykonaj_ruch(ruchy_gracza[i]), ruchy_komputera[i], punkty_gracza[i], punkty_komputera[i]);
    }
}
int main() {

    int punkty_gracza = 0;
    int punkty_komputera = 0;
    int ruchy_gracza[100];
    char* ruchy_komputera[100];
    int liczba_rund = 0;
    int wyniki_gracza[100];
    int wyniki_komputera[100];


    while(punkty_gracza < 3 && punkty_komputera < 3){
        int ruch_gracza;
        printf("Wybierz swoj ruch: \n");
        printf("0 - papier\n");
        printf("1 - kamien\n");
        printf("2 - nozyce\n");
        scanf("%d", &ruch_gracza);

        ruchy_gracza[liczba_rund] = ruch_gracza;
        ruchy_komputera[liczba_rund] = ruch_komputera();
        liczba_rund++;

        printf("Twoj ruch: %s\n", wykonaj_ruch(ruch_gracza));
        printf("Ruch komputera: %s\n", ruch_komputera());

        int ruch_komputera_int;

        if(strcmp(ruch_komputera(), "papier") == 0) {
            ruch_komputera_int = 0;
        }
        else if(strcmp(ruch_komputera(), "kamien") == 0) {
            ruch_komputera_int = 1;
        }
        else {
            ruch_komputera_int = 2;
        }

        if(ruch_gracza == ruch_komputera_int) {
            printf("Remis\n");
        }
        else if(((ruch_gracza == 1) && (ruch_komputera_int == 2)) ||
                ((ruch_gracza == 2) && (ruch_komputera_int == 0)) ||
                ((ruch_gracza == 0) && (ruch_komputera_int == 1))) {
            printf("Wygrales!\n");
            punkty_gracza += 1;
        }
        else {
            printf("Wygral komputer\n");
            punkty_komputera += 1;
        }
        wyniki_gracza[liczba_rund-1] = punkty_gracza;
        wyniki_komputera[liczba_rund-1] = punkty_komputera;
        printf("WYNIK = %d:%d\n",punkty_gracza, punkty_komputera);
    }

    printf("Wpisz 'scores' aby zobaczyc przebieg gry");

    scores(ruchy_gracza, ruchy_komputera, liczba_rund, wyniki_komputera, wyniki_gracza);

    return 0;
}
