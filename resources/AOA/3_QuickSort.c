#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int p, int r) {
  int x = array[r];
  int i = (p - 1);
  for (int j = p; j < r; j++) {
    if (array[j] <= x) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[r]);
  return (i + 1);
}

void quickSort(int array[], int p, int r) {
  if (p < r) {
    int q = partition(array, p, r);
    quickSort(array, p, q - 1);
    quickSort(array, q + 1, r);
  }
}

int main() {
  int array[50],n,i;  
  printf("Enter the no. of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
 
  quickSort(array, 0, n - 1);  
 printf("\nSorted elements are: ");
    for(i=0;i<n;i++)
    {
    printf("%d ",array[i]);
    }
}