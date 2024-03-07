#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x, y) (x > y ? 1 : ((x < y) ? -1 : 0))
#define MAX_TERMS 1000

typedef struct {
    int coef;
    int expon;
} polynomial;

int readP(polynomial term[], FILE* input, int startWrite);
void addP(polynomial term[], int coef, int expon);

int main(void) {

    polynomial terms[MAX_TERMS];
    int avail = 0;
    int sa, fa, sb, fb, sc, fc;

    FILE* input1, *input2;

    if ((input1 = fopen("a3.txt", "r+")) == NULL) {
        printf("���� �б� ����! \n");
        return 0;
    }

    if ((input2 = fopen("b3.txt", "r+")) == NULL) {
        printf("���� �б� ����! \n");
        return 0;
    }

    printf("A(x):");
    sa = 0;
    fa = readP(terms, input1, sa) - 1; // readP�� ���� ������ ��ȯ�߱� ������ �迭 �ּҴ� arr[���� - 1]��

    for (int i = sa; i < fa; i++) printf("%d^%d + ", terms[i].coef, terms[i].expon);
    printf("%d^%d\n", terms[fa].coef, terms[fa].expon);

    printf("B(x):");
    sb = fa + 1;
    fb = readP(terms, input2, sb) - 1;

    for (int i = sb; i < fb; i++) printf("%d^%d + ", terms[i].coef, terms[i].expon);
    printf("%d^%d\n", terms[fb].coef, terms[fb].expon);

    sc = fb + 1;

    while ((sa <= fa + 1) && (sb <= fb + 1)) {
        if ((sa == fa + 1) && (sb == fb + 1)) break;
        
        int bigCoef = COMPARE(terms[sa].expon, terms[sb].expon); // �� ������ �ڵ�? (����)
        if (sa > fa) bigCoef = -1;
        if (sb > fb) bigCoef = 1;

        switch (bigCoef) {
        case -1:
            addP(&terms[sc], terms[sb].coef, terms[sb].expon);
            sb++;
            sc++;
            break;
        case 0:
            if ((terms[sa].coef + terms[sb].coef) == 0) {
                sa++;
                sb++;
                continue;
            }
            addP(&terms[sc], terms[sa].coef + terms[sb].coef, terms[sa].expon);
            sa++;
            sb++;
            sc++;
            break;
        case 1:
            addP(&terms[sc], terms[sa].coef, terms[sa].expon);
            sa++;
            sc++;
            break;
        }
    }

    fc = sc; // ?? ���߿� ���� �ľ� (����)
    sc = fb + 1;

    // printf("sa %d fa %d sb %d fb %d sc %d fc %d\n",sa,fa,sb,fb,sc,fc);

    printf("\nC(x):");
    if (sc == fc) printf("0");
    else {
        for (int i = sc; i < fc; i++) printf("%d^%d + ", terms[i].coef, terms[i].expon);
            printf("%d^%d\n", terms[fc].coef, terms[fc].expon);

    }
    
    /*
    if (sc <= fc) { // sc ���ķ� ���� �ԷµǾ�����: > �̷��� ó���ص� �Ǵ� ������? (����)
        for (int i = sc; i < fc; i++) printf("%d^%d + ", terms[i].coef, terms[i].expon);
        printf("%d^%d\n", terms[fc].coef, terms[fc].expon);
    }
    else printf("0"); // == �ƹ��͵� �Է��� �� �Ǿ��� == C(x) = 0
    */

    return 0;
}

int readP(polynomial term[], FILE* input, int startWrite) {
    while (fscanf(input, "%d %d", &(term[startWrite].coef), &(term[startWrite].expon)) != -1) startWrite++;
    return startWrite;
}

void addP(polynomial term[], int coef, int expon) {
    term->coef = coef;
    term->expon = expon;
}