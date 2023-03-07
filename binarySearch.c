#include<stdio.h>
int main()
{
    int arr[100],n,item,start,mid,end,flag=0;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("The sorted array is\n");
     for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nEnter the element to be searched : ");
    scanf("%d",&item);
    start=0;
    end=n-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==item)
        {
            flag=1;
            printf("Element found at %d\n",mid);
            break;
        }
        else if(item<arr[mid])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    if(flag==0)
    {
        printf("Element not found\n");
    }
    return 0;
}