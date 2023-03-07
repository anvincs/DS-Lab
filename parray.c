#include<stdio.h>
int main()
{
    int n,arr[100];
    int *ptr = arr;
    printf("Enter the size of the array : ");
    scanf("&d",&n);
    printf("Enter the elements \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",(ptr+i));
    }
    printf("The elements of the array are \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(ptr+i));
    }
    return 0;
}