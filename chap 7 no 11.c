#include <stdio.h>
#include <stdlib.h>

void mergeArrays(double *array1, int size1, double *array2, int size2, double *result, int *resultSize) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (array1[i] < array2[j]) {
            result[k++] = array1[i++];
        } else {
            result[k++] = array2[j++];
        }
    }

    while (i < size1) {
        result[k++] = array1[i++];
    }

    while (j < size2) {
        result[k++] = array2[j++];
    }

    *resultSize = k;
}

int main() {
    double array1[] = {-10.5, -1.8, 3.5, 6.3, 7.2};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    double array2[] = {-1.8, 3.1, 6.3};
    int size2 = sizeof(array2) / sizeof(array2[0]);
    
    double *result = malloc((size1 + size2) * sizeof(double));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    int resultSize;
    mergeArrays(array1, size1, array2, size2, result, &resultSize);

    for (int i = 0; i < resultSize; i++) {
        printf("%.1f ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}