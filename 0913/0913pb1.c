#include <stdio.h>
#include <stdlib.h>

int main(void) {

    FILE* input1, *input2;

    if ((input1 = fopen("in1.txt", "r+")) == NULL) {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    if ((input2 = fopen("in2.txt", "r+")) == NULL) {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    /*
    int* ptr1 = malloc(sizeof(int));
    fscanf(input1, "%d", ptr1);
    ptr1 = realloc(ptr1, (sizeof(int)) * (*ptr1));
    */

    int size1 = 0;
    fscanf(input1, "%d", &size1);
    int* ptr1 = malloc(sizeof(int) * size1);

    for (int i = 0; i < size1; i++) {
        fscanf(input1, "%d", (ptr1 + i));
    }

    int size2 = 0;
    fscanf(input2, "%d", &size2);
    int* ptr2 = malloc(sizeof(int) * size2);

    for (int i = 0; i < size2; i++) {
        fscanf(input2, "%d", (ptr2 + i));
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (*(ptr1 + i) == *(ptr2 + j)) printf("%d ", *(ptr1 + i));
        }
    }

    return 0;
}