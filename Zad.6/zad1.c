#include <stdio.h>


union Dane{
    int calkowita;
    float zmienno;
    char znak;
};
int main() {

    union Dane dane;
    dane.calkowita = 150;
    printf("Wartosc typu int: %i\n", dane.calkowita);

    dane.zmienno = 14.234123;
    printf("Wartosc typu float: %f\n", dane.zmienno);

    dane.znak = 'c';
    printf("wartosc typu char: %c", dane.znak);

    return 0;
}
