#include<stdio.h>

void display(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void selectionSort(int *a,int n)
{
    int mi;
    for(int i=0;i<n-1;i++)
    {
        mi=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[mi])
            {
                mi=j;
            }
        }
        int temp=a[i];
        a[i]=a[mi];
        a[mi]=temp;
    }
}


int main()
{
    int arr[100],n;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("The array is\n");
    display(arr,n);
    selectionSort(arr,n);
    printf("The sorted array is\n");
    display(arr,n);

    return 0;
}