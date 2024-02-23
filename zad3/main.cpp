#include <iostream>

int obliczsilnie(int n){
    if(n == 0){
        return 1;
    }
    else{
        int silnia = 1;
        for (int i = 2;i <=n; i++){
            silnia *= i;
        }
        return silnia;
    }
}

int main() {
    int array[] = {1, 2,3,4,5,6,7,8,9,10};

    printf("{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}\n");


    for(int i = 0; i < 10; i++){
        printf("Silnia wynosi: %d\n", obliczsilnie(array[i]));
    }

    return 0;
}
