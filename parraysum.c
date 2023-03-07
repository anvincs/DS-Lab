#include<stdio.h>
int arraysum(int *ptr,int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=*(ptr+i);
    }
    return sum;
}
int main()
{
    int n,arr[100];
    int *p=arr;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("Enter the elements of the array \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",(p+i));
    }
    printf("Sum of all elements of the array = %d",arraysum(arr,n));
    return 0;
}