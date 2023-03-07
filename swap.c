#include<stdio.h>
void swap(int *n1,int *n2)
{
    int temp;
    temp=*n1;
    *n1=*n2;
    *n2=temp;
}
int main()
{
    int a,b;
    printf("Enter the value of a : ");
    scanf("%d",&a);
    printf("Enter the value of b : ");
    scanf("%d",&b);
    swap(&a,&b);
    printf("After swapping \n");
    printf("a=%d  b=%d",a,b);
    return 0;
}