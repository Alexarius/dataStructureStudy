#include <stdio.h>
#define COMPARE(x, y) (x > y ? 1 : ((x < y) ? -1 : 0))

int binSearch (int list[], int searchNum, int left, int right);
int binRecur (int list[], int searchNum, int left, int right);

int main() {

  FILE* inputC;

  if ((inputC = fopen("input.txt", "r+")) == NULL) {
    printf("파일 읽기 오류! \n");
    return 0;
  }

  int numArr[100] = {0};
  int arrSize = 0;

  while (fscanf(inputC, "%d", &numArr[arrSize]) != -1) arrSize++;

  int search = 0;

  while(1) {
    printf("Input number: ");
    scanf("%d", &search);
    if(search < 0) break;

    printf("iterative binary search: ");
    if (binSearch(numArr, search, 0, arrSize) != -1) printf("있음\n");
    else printf("없음\n");
    
    printf("recursive binary search: ");
    if (binRecur(numArr, search, 0, arrSize) != -1) printf("있음\n");
    else printf("없음\n");
  }
    
  printf("Exit");

  return 0;
}

int binSearch (int list[], int searchNum, int left, int right) {
  int middle;
  while(left <= right) {
    middle = (left + right) / 2;
    switch (COMPARE(list[middle], searchNum)) {
    case -1: left = middle + 1;
      break;
    case 0: return middle;
    case 1: right = middle-1;
    }
  }
  return -1;
}

int binRecur (int list[], int searchNum, int left, int right) {
  int middle;
  if (left <= right) {
    middle = (left + right) / 2;
    switch (COMPARE(list[middle], searchNum)) {
    case -1: return binRecur(list, searchNum, middle+1, right);
    case 0: return middle;
    case 1: return binRecur(list, searchNum, left, middle-1);
    }
  }
  return -1;
}