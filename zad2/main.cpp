#include <iostream>

int main() {
    //zad2

    int math[5] = {5,3,4,2,5};
    int phis[5] = {3,1,4,6,4};
    int grades[2][5];
    float avg_math = 0;
    float avg_phis = 0;
    float sum_math = 0;
    float sum_phis = 0;
    int counter = 0;

    for(int i = 0; i < 5; i++){
        grades[0][i] = math[i];
        grades[1][i] = phis[i];
        sum_math += math[i];
        sum_phis += phis[i];
        counter++;
    }

    avg_math = sum_math/counter;
    avg_phis = sum_phis/counter;

    printf("Srednia ocen z matematyki: %.2f\n ", avg_math);
    printf("Srednia ocen z fizyki: %.2f", avg_phis);

    return 0;

}
