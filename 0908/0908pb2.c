#include <stdio.h>

void recurBin(int num);
int zeroNum (int num);

int main(void) {

    int num = 0;

    while (1) {
        printf("Input num: ");
        scanf("%d",&num);
        if(num < 0) break;

        printf("2진표현: ");
        recurBin(num);
        printf("\n%d내 0은 %d개 있다.\n", num, zeroNum(num));
    }

    printf("Exit");
    
    return 0;
}

void recurBin(int num) {
    if (num < 2) printf("%d", num % 2);
    else {
        recurBin(num / 2);
        printf("%d", num % 2);
    }
}

int zeroNum (int num) {
    if (num == 1) return 0;
    else if ((num % 2) != 0) return zeroNum(num / 2);
    else return (1 + zeroNum(num / 2));
}