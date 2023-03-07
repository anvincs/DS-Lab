#include<stdio.h>
int main()
{
    int arr[100],n,item,flag=0;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched : ");
    scanf("%d",&item);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==item)
        {
            flag=1;
            printf("Element found at index %d\n",i);
        }
    }
    if(flag==0)
    {
        printf("Element not found\n");
    }
    return 0;
}