#include <stdio.h>
#include <stdlib.h>

int main(void) {

    FILE* input, *add, *out;

    if ((input = fopen("in.txt", "r+")) == NULL) {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    if ((add = fopen("add.txt", "r+")) == NULL) {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    if ((out = fopen("add.txt", "w+")) == NULL) {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    return 0;
}