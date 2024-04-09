#include <stdio.h>
#include <stdlib.h>

int** generateTriangle(int height) {
    int** triangle = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; ++i) {
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        triangle[i][0] = 1;
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle[i][i] = 1;
    }
    return triangle;
}

void drawTriangle(int** triangle, int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

void freePascalTriangle(int** triangle, int height) {
    for (int i = 0; i < height; ++i) {
        free(triangle[i]);
    }
    free(triangle);
}

int main() {
    int height;
    printf("Podaj wysokosc trojkata Pascala: ");
    scanf("%d", &height);

    int** triangle = generateTriangle(height);
    drawTriangle(triangle, height);
    freePascalTriangle(triangle, height);

    return 0;
}
