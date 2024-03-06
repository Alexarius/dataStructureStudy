#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int row = 0, col = 0;

    printf("row size:");
    scanf("%d", &row);
    printf("col size:");
    scanf("%d", &col);

    int** arr = (int**)malloc(sizeof(int*) * col);

    for(int i=0; i<col; i++) {
        *(arr+i) = (int*)malloc(sizeof(int)*row);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            *(*(arr + j) + i) = (i*i) + (j*j);
            printf("%4d",*(*(arr+j)+i));
        }
        printf("\n");
    }

    for(int i=0; i<row; i++) {
        free(*(arr+i));
        printf("free arr[%d]\n", i);
    }

    free(arr);
    printf("free arr");

    return 0;
}