#include <stdio.h>

int main() {

    int liczba;
    int suma = 0;
    printf("Podaj dowolna liczbe: ");
    scanf("%d",&liczba);

    if(liczba >=0){
        for(int i = 1; i < liczba; i++){
            if(i % 3 == 0 || i % 5 == 0){
                printf("%d\n", i);
                suma += i;
            }
        }
        printf("suma wielokrotnosci = %d", suma);
    }
    else{
        printf("Podana liczba nie jest liczbą naturalną");
    }

    return 0;
}
