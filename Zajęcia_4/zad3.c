#include <stdio.h>


void swap(int *array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
void generate_permutations(int *array, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(array, start, i);
        generate_permutations(array, start + 1, end);
        swap(array, start, i);
    }
}
int main() {
    int n;
    printf("Podaj liczbe elementow w ciagu: ");
    scanf("%d", &n);

    int array[n];
    printf("Podaj elementy ciagu: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Permutacje ciagu:\n");
    generate_permutations(array, 0, n - 1);

    return 0;
}