#include<stdio.h>
int max(int a[],int size)
{
    int m=a[0];
    for(int i=1;i<size;i++)
    {
        if(a[i]>m)
        {
            m=a[i];
        }
    }
    return m;
}
int main()
{
    int s,arr[100];
    printf("Enter size of array \n");
    scanf("%d",&s);
    printf("Enter the elements \n");
    for(int i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The biggest element is  %d",max(arr,s));
    return 0;
}