#include <stdio.h>

float dodawanie(float x, float y){
    return x + y;
}
float mnozenie(float x, float y){
    return x * y;
}
float odejmowanie(float x, float y){
    return x - y;
}
int main() {

    float(*wskaznik)(float, float);

    printf("Jaka operacje chcesz wykonac?\n");
    printf("1 - dodawanie\n");
    printf("2 - odejmowanie\n");
    printf("3 - mnozenie\n");
    int wybor;
    scanf("%d", &wybor);
    switch(wybor){
        case 1:
            wskaznik = &dodawanie;
            printf("%.2f", wskaznik(2,5));
            break;
        case 2:
            wskaznik = &odejmowanie;
            printf("%.2f", wskaznik(2,5));
            break;
        case 3:
            wskaznik = &mnozenie;
            printf("%.2f", wskaznik(2,5));
            break;
    }

    return 0;
}
