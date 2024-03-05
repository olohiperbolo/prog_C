#include <stdio.h>

void podwajanie(float *x){
    *x *= 2;
}
int main() {
    float a = 15.124;
    podwajanie(&a);
    printf("Podwojona liczba: %f", a);

    return 0;
}
