#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char imie[30];
    float ocenaKoncowa;
}Student;

int sort(const void *a, const void *b){
    const Student *student_a = (const Student *)a;
    const Student *student_b = (const Student *)b;

    if (student_a->ocenaKoncowa < student_b->ocenaKoncowa)
        return 1;
    else if (student_a->ocenaKoncowa > student_b->ocenaKoncowa)
        return -1;
    else
        return 0;
}

void sortujMalejaco(Student *tablica_studentow, int rozmiar){
    qsort(tablica_studentow, rozmiar, sizeof(Student), sort);
}

int main() {

    Student dane[] = {
            {"Aleksander", 4.0},
            {"Michal", 4.5},
            {"Dawid", 2.0},
            {"Maciek", 3.5},
            {"Robert", 5.0}
    };
    int rozmiar_tablicy = sizeof(dane) / sizeof(dane[0]);

    sortujMalejaco(dane, rozmiar_tablicy);

    printf("Tablica posortowana:\n");
    for (int i = 0; i < rozmiar_tablicy; ++i) {
        printf("Imie: %s, Ocena: %.1f\n", dane[i].imie, dane[i].ocenaKoncowa);
    }

    return 0;
}
