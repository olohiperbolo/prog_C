#include <stdio.h>

unsigned int factorial(int a){
    if(a == 0){
        return 1;
    }
    else{
        int wynik = a * factorial(a - 1);
        return wynik;
    }
}
int main() {

    int liczba;
    printf("Podaj liczbe: ");
    scanf("%d", &liczba);
    printf("silnia = %d", factorial(liczba));
    return 0;
}
