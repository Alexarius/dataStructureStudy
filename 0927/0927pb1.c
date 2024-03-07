#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPARE(x, y) (x > y ? 1 : ((x < y) ? -1 : 0))

typedef struct {
    int number;
    char name[10];
} person;

int readP(person term[], FILE* input, int startWrite);
void addP(person term[], int number, char personName[]);
void writeP(person term[], FILE* output, int startRead, int endRead);

int main(void) {

    person people[100];
    int sIn, fIn, sAdd, fAdd, sOut, fOut;

    FILE* inputF, *addF, *outF;

    if ((inputF = fopen("in.txt", "r+")) == NULL) {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    if ((addF= fopen("add.txt", "r+")) == NULL) {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    if ((outF = fopen("out.txt", "w+")) == NULL) {
        printf("파일 읽기 오류! \n");
        return 0;
    }

    sIn = 0;
    fIn = readP(people, inputF, sIn) - 1;

    printf("<in.txt>\n");
    for (int i = sIn; i <= fIn; i++) printf("%d %s\n", people[i].number, people[i].name);

    printf("\n<add.txt>\n");
    sAdd = fIn + 1;
    fAdd = readP(people, addF, sAdd) - 1;

    for (int i = sAdd; i <= fAdd; i++) printf("%d %s\n", people[i].number, people[i].name);

    sOut = fAdd + 1;

    while ((sIn <= fIn + 1) && (sAdd <= fAdd + 1)) {
        if ((sIn == fIn + 1) && (sAdd == fAdd + 1)) break;
        
        int smallerNum = COMPARE(people[sIn].number, people[sAdd].number);
        if (sIn > fIn) smallerNum = 1; // IN쪽 사람의 number가 모두 ADD보다 작았음 > 이제 ADD만 할 차례
        if (sAdd > fAdd) smallerNum = -1; // 위와 반대

        switch (smallerNum) {
        case -1:
            addP(&people[sOut], people[sIn].number, people[sIn].name);
            sIn++;
            sOut++;
            break;
        case 0:
            addP(&people[sOut], people[sIn].number, "ERROR");
            sIn++;
            sAdd++;
            sOut++;
            break;
        case 1:
            addP(&people[sOut], people[sAdd].number, people[sAdd].name);
            sAdd++;
            sOut++;
            break;
        }
    }

    fOut = sOut;
    sOut = fAdd + 1;

    writeP(people, outF, sOut, fOut);

    printf("\n<out.txt>\n");
    for (int i = sOut; i < fOut; i++) {
        if(strcmp(people[i].name, "ERROR") == 0) {
            printf("%2d:%6s\n", people[i].number, people[i].name);
            continue;
        }
        printf("%2d,%6s\n", people[i].number, people[i].name);
    }

    // fOut칸에 165 들어있음? 체크 (질문)

    return 0;
}

int readP(person term[], FILE* input, int startWrite) {
    while (fscanf(input, "%d %s", &(term[startWrite].number), (term[startWrite].name)) != -1) startWrite++;
    return startWrite;
}

void addP(person term[], int number, char personName[]) {
    term->number = number;
    strcpy(term->name, personName);
}

void writeP(person term[], FILE* output, int startRead, int endRead) {
    while (startRead < endRead) {
        fprintf(output, "%d %s\n", (term[startRead].number), (term[startRead].name));
        startRead++;
    }
}