#include <iostream>

//zad5
int main() {

    int liczba;
    printf("Podaj dowolna liczbe: ");
    scanf("%d",&liczba);

    if(liczba >=0){
        for(int i = 1; i < liczba; i++){
            if(i % 3 == 0 || i % 5 == 0){
                printf("%d\n", i);
            }
        }
    }
    else{
        printf("Podana liczba nie jest liczbą naturalną");
    }

    return 0;
}
