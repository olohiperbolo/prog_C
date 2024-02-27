#include <stdio.h>

//zad4
int main() {
    for(int i = 1; i <= 200; i++){
        printf("\n%d",i);
        if(i % 7 == 0 && i % 5 == 0){
            printf("FooBar");
        }
        else if(i % 5 == 0){
            printf("Foo");
        }
        else if(i % 7 == 0){
            printf("Bar");
        }

    }
}

