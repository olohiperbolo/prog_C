#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **generateMatrix(int rows, int columns){
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; ++i){
        matrix[i] = (int*)malloc(columns * sizeof(int));
    }
    return matrix;
}

void fillMatrix(int** matrix, int rows, int columns){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            matrix[i][j] = rand() % 100;
        }
    }
}

void drawMatrix(int** matrix, int rows, int columns){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < columns; ++j){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeAllocate(int** matrix, int rows){
    for(int i = 0; i < rows; ++i){
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    srand(time(NULL));

    int rows, columns;
    printf("Podaj liczbe wierszy: ");
    scanf("%d", &rows);
    printf("Podaj liczbe kolumn: ");
    scanf("%d", &columns);

    int** matrix = generateMatrix(rows, columns);
    fillMatrix(matrix,rows,columns);
    printf("Macierz: \n");

    drawMatrix(matrix, rows,columns);
    freeAllocate(matrix,rows);
    return 0;
}
