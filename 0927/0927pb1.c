#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int number;
    char name[10];
} person;

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

int readP(person term[], FILE* input, int startWrite) {
    while (fscanf(input, "%d %s", &(term[startWrite].number), (term[startWrite].name)) != -1) startWrite++;
    return startWrite;
}

void addP(person term[], int number, char personName[]) {
    term->number = number;
    strcpy(&term->name, personName);
}