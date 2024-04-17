#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int znajdzLiczbe(char *word) {
    if (strcmp(word, "zero") == 0) return 0;
    else if (strcmp(word, "one") == 0) return 1;
    else if (strcmp(word, "two") == 0) return 2;
    else if (strcmp(word, "three") == 0) return 3;
    else if (strcmp(word, "four") == 0) return 4;
    else if (strcmp(word, "five") == 0) return 5;
    else if (strcmp(word, "six") == 0) return 6;
    else if (strcmp(word, "seven") == 0) return 7;
    else if (strcmp(word, "eight") == 0) return 8;
    else if (strcmp(word, "nine") == 0) return 9;
    else return -1;
}

int main() {
    char linia[100];

    FILE *fp;

    fp = fopen("C:\\Users\\aleks\\Downloads\\input.txt", "r");
    if (fp == NULL) {
        printf("Bledna nazwa pliku.\n");
        return 1;
    }

    while (fgets(linia, 100, fp) != NULL) {
        int pierwsza = -1, ostatnia = -1;

        for (int i = 0; linia[i] != '\0'; i++) {
            char znak = linia[i];
            if (isdigit(znak)) {
                if (pierwsza == -1) pierwsza = znak - '0';
                ostatnia = znak - '0';
            } else if (isalpha(znak)) {
                char slowo[6];
                for (int k = 0; k < 5 && (i + k) < 100; k++) {
                    slowo[k] = linia[i + k];
                    slowo[k + 1] = '\0';
                    int liczba = znajdzLiczbe(slowo);
                    if (liczba != -1) {
                        if (pierwsza == -1) pierwsza = liczba;
                        else ostatnia = liczba;
                    }
                }
            }
        }

        printf("%s : %d%d\n", linia, pierwsza, ostatnia);
    }
    fclose(fp);

    return 0;
}
