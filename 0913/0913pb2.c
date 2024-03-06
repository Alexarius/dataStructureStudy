#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int row = 0, col = 0;

    printf("row size:");
    scanf("%d", &row);
    printf("col size:");
    scanf("%d", &col);

    int** arr;

    arr =  malloc(sizeof(int) * col * row);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            *(*(arr + j) + i) = (i*i) + (j*j);
            // printf("%d %d %d %d\n",*(*(arr+j)+i), i, j, (i*i) + (j*j));
        }
    }

    /*
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d",*(*(arr+j)+i));
        }
        printf("\n");
    }
    */

    return 0;
}