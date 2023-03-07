#include<stdio.h>

void display(int* a,int n) 
{
   for(int i=0;i<n;i++) 
   {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insertionSort(int *a,int n) 
{
    int num,j;
    for(int i=1;i<n;i++) 
    {
        num=a[i];
        j=i-1;
        while(j>=0 && num<a[j]) 
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=num;
    }
}

int main() 
{
    int arr[100],n;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("The array is\n");
    display(arr,n);
    insertionSort(arr,n);
    printf("The sorted array is\n");
    display(arr,n);

    return 0;
}