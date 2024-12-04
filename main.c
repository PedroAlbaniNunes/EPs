#include <stdio.h>
#include <stdlib.h>

int* flattenLowerTriangular(int** matrix, int dimension) {
    int* result = (int*) malloc(dimension * (dimension + 1) / 2 * sizeof(int));
    int index = 0;
    for (int row = 0; row < dimension; row++) {
        for (int col = 0; col <= row; col++) {
            result[index++] = matrix[row][col];
        }
    }
    return result;
}

int main() {
    int size = 3;
    int** array2D = (int**) malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        array2D[i] = (int*) malloc(size * sizeof(int));
    }

    array2D[0][0] = 1;
    array2D[0][1] = 0;
    array2D[0][2] = 0;
    array2D[1][0] = 2;
    array2D[1][1] = 5;
    array2D[1][2] = 0;
    array2D[2][0] = 3;
    array2D[2][1] = 6;
    array2D[2][2] = -2;

    int* flattenedArray = flattenLowerTriangular(array2D, size);
    
    for (int i = 0; i < size * (size + 1) / 2; i++) {
        printf("%d ", flattenedArray[i]);
    }

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(array2D[i]);
    }
    free(array2D);
    free(flattenedArray);

    return 0;
}