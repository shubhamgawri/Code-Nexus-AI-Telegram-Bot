#include <stdio.h>

void merge(int A[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = A[p + i];
  for (int j = 0; j < n2; j++)
    R[j] = A[q + 1 + j];

  int i=0, j=0, k=p;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    A[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    A[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int A[], int p, int r) {
  if (p < r) {
    int q = (p + r)/2;
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

void printArray(int A[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");
}

int main() 
{
    int i,n;
    printf("Enter the no. of elements:");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    merge_sort(A, 0, n - 1);
    printf("Sorted Aay is: \n");
    printArray(A, n);
}