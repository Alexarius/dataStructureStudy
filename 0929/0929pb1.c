#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* chkFileNull(FILE* getFile, char fileName[], char readMode[]);
void readFromFile(FILE* input, int* dyArr);
void pushN(FILE* input, int* dyArr, int count);
int popN(int* dyArr, int count);
void printArr(int* dyArr, int count);

int main() {

    FILE* input = chkFileNull(input, "in2.txt", "r+");

    int* dyArr = (int*)malloc(sizeof(int));
    
    readFromFile(input, dyArr);

    return 0;
}

FILE* chkFileNull(FILE* getFile, char fileName[], char readMode[]) {
    if ((getFile = fopen(fileName, readMode)) == NULL) {
        printf("파일 읽기 오류! \n");
        return 0;
    }
}

void readFromFile(FILE* input, int* dyArr) {
    int count = 0;
    int capacity = 1; // 초기크기
    char mode;

    while (fscanf(input, "%c", &mode) != -1) {
        if (mode == 'I') {
            if (count == capacity) {
                realloc(dyArr, sizeof(int) * capacity);
                capacity *= 2;
                pushN(input, dyArr, count);
                count++;
                printf("  doubling: %d", capacity); // push Item 뒤에 doubling 프린트 위해서 두번적음...
                printf("\n"); // printArr안에 넣으면 두번째 인풋 마지막이랑 다름...
                printArr(dyArr, count);
            }
            else { 
                pushN(input, dyArr, count);
                count++;
                printf("\n");
                printArr(dyArr,count);
            }
        }
        else if (mode == 'D'){
            popN(dyArr, count);
            if(count > 0) count--;
            printf("\n");
            printArr(dyArr, count);
        }
        else continue;
    }
}

void pushN(FILE* input, int* dyArr, int count) {
    int num;
    fscanf(input, "%d", &num);
    printf("push item: %d", num);
    *(dyArr+count) = num;
}

int popN(int* dyArr, int count) {
    printf("pop");
    if (count == 0) {
        printf("\nstack empty: cannot POP!");
        return -1;
    }
    return *(dyArr+count--);
}

void printArr(int* dyArr, int count) {
    for(int i = 0; i < count; i++) {
        printf("[%2d]", *(dyArr+i));
    }
    printf("\n");
}