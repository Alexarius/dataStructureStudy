#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 1000

typedef struct {
    int coef;
    int expon;
} polynomial;

int readP(polynomial term[], FILE* input, int startWrite);

int main(void) {

    polynomial terms[MAX_TERMS];
    int avail = 0;
    int sa, fa, sb, fb, sc, fc;

    FILE* input1, *input2;

    if ((input1 = fopen("a1.txt", "r+")) == NULL) {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    if ((input2 = fopen("b1.txt", "r+")) == NULL) {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    sa = 0;
    fa = readP(terms, input1, sa);
    sb = fa + 1;
    fb = readP(terms, input2, sb);

    printf("OK?");

    for (int i = 0; i < fb; i++) {
        printf("%d %d\n", terms[i].coef, terms[i].expon);
    }

    return 0;
}

int readP(polynomial term[], FILE* input, int startWrite) {
    while (fscanf(input, "%d %d", (term[startWrite].coef), (term[startWrite].expon)) != -1) {
        startWrite++;
        printf("read ok %d", startWrite);
    }
    return startWrite;
}