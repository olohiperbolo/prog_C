#include <stdio.h>
#include <string.h>

#define MAX_KONTAKTOW 100


typedef struct{
    char imie[30];
    char nazwisko[30];
    int numer_telefonu[9];
}Contact;

void DodajKontakt(Contact lista[], int *rozmiar, char * imie, char * nazwisko, int * numer){
    if(*rozmiar < MAX_KONTAKTOW){
        strcpy(lista[*rozmiar].imie, imie);
        strcpy(lista[*rozmiar].nazwisko, nazwisko);
        strcpy(lista[*rozmiar].numer_telefonu, numer);
        (*rozmiar++);
    }
    else{
        printf("Lista kontaktow jest pelna");
    }
}
int ZnajdzKontakt(Contact lista[], int rozmiar, char *nazwisko){
    for(int i = 0; i < rozmiar; i++){
        if(strcpy(lista[i].nazwisko,nazwisko) == 0){
            return i;
        }
    }
    return -1;
}

int UsunKontakt(Contact lista[], int *rozmiar, char * nazwisko){

}
void WyswietlKontakty(Contact * lista, int rozmiar){
    for (int i = 0; i < rozmiar; i++){
        printf("Imie: %s\nNazwisko: %s\nnr-tel: %d\n",lista[i].imie,
               lista[i].nazwisko,
               lista[i].numer_telefonu);
    }
}

int main() {

    Contact lista[MAX_KONTAKTOW];
    int rozmiar = 0;

    int opcja;
    do {
        printf("Wybierz opcje:\n");
        printf("1. Wyswietl kontakty\n");
        printf("2. Dodaj kontakt\n");
        printf("3. Usun kontakt\n");
        printf("4. Wyszukaj kontakt\n");
        printf("0. Wyjdz\n");
        scanf("%d", &opcja);

        switch (opcja) {
            case 1:
                printf("Kontakty:\n");
                WyswietlKontakty(lista, rozmiar);
                break;
            case 2: {
                char imie[30];
                char nazwisko[30];
                char numer[10];
                printf("Podaj imie: ");
                scanf("%s", imie);
                printf("Podaj nazwisko: ");
                scanf("%s", nazwisko);
                printf("Podaj numer telefonu: ");
                scanf("%s", numer);
                DodajKontakt(lista, &rozmiar, imie, nazwisko, numer);
                break;
            }
            case 3: {
                char szukaneNazwisko[30];
                printf("Podaj nazwisko kontaktu do usuniecia: ");
                scanf("%s", szukaneNazwisko);
                break;
            }
            case 4:
                ZnajdzKontakt();
                break;
            case 0:
                printf("Koniec programu.\n");
                break;
            default:
                printf("Nieprawidlowa opcja. Wybierz jeszcze raz.\n");
        }
    } while (opcja != 0);

    return 0;
}
