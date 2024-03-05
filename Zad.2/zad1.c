#include <stdio.h>

int main() {
    int x = 1;
    int * pA = &x;
    *pA += 22;

    printf("Wartosc bezposrednio = %d\n", x);
    printf("Wartosc przez wskaznik = %d", *pA);

    return 0;
}
