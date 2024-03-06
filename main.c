#include <stdio.h>
#include <stdlib.h>

int* arrayAdd(int *arr1, int *arr2, int size);
void swapArr(int** arr1, int** arr2);

int main() {

  int size = 0;

  printf("Input size: ");
  scanf("%d", &size);

  int* ptr1 = malloc(sizeof(int) * size);
  int* ptr2 = malloc(sizeof(int) * size);
  
  for (int i = 0; i < size; i++) {
		ptr1[i] = rand()%21;
    ptr2[i] = rand()%21;
	}

    int* sumArr = arrayAdd(ptr1, ptr2, size);

    for(int i = 0; i < size; i++) printf("%d ",ptr1[i]);
    printf("\n");
    for(int i = 0; i < size; i++) printf("%d ",ptr2[i]);
    printf("\n\n");

    swapArr(&ptr1, &ptr2);
    for(int i = 0; i < size; i++) printf("%d ",ptr1[i]);
    printf("\n");
    for(int i = 0; i < size; i++) printf("%d ",ptr2[i]);
    printf("\n\n");

    for(int i = 0; i < size; i++) printf("%d ",sumArr[i]);

    return 0;
}

int* arrayAdd(int arr1[], int arr2[], int size) {
  int* sumArr = malloc(sizeof(int) * size);

  for (int i = 0; i < size; i++) {
		sumArr[i] = arr1[i] + arr2[i]; 
	}

  return sumArr;
}

void swapArr(int** arr1, int** arr2) {
  int* temp;
  temp = *arr1;
  *arr1 = *arr2;
  *arr2 = temp;
}