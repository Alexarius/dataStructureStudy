#include <stdio.h>
#include <stdlib.h>

int main(void) {

    FILE* input, *add, *out;

    if ((input = fopen("in.txt", "r+")) == NULL) {
        printf("���� �б� ����! \n");
        return 0;
    }

    if ((add = fopen("add.txt", "r+")) == NULL) {
        printf("���� �б� ����! \n");
        return 0;
    }

    if ((out = fopen("add.txt", "w+")) == NULL) {
        printf("���� �б� ����! \n");
        return 0;
    }

    return 0;
}