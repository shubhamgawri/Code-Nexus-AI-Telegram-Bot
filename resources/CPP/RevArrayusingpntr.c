#include<stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int array[],int array_size)
{
    int *pointer1 = array;
    int *pointer2 = array + array_size - 1;
    while(pointer1<pointer2)
    {
        swap(pointer1,pointer2);
        pointer1++;
        pointer2--;
    }
}

void display(int *array,int array_size)
{
    int *length = array + array_size;
    int *position = array;
    printf("array= ");
    for(position = array;position<length;position++)
    {
        printf("%d\t",*position);
    }
}

int main()
{
    int n;
    printf("Enter array size:");
    scanf("%d",&n);
    int array[n];
    printf("Enter array elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Original array ");
    display(array,n);
    printf("\n");
    printf("Reversed array");
    reverse(array,n);
    display(array,n);
    return 0;
}