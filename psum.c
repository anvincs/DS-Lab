#include<stdio.h>
int main()
{
    int n1,n2,sum,*a,*b;
    printf("Enter two integers to add : ");
    scanf("%d%d",&n1,&n2);
    a=&n1;
    b=&n2;
    sum=*a+*b;
    printf("Sum of numbers = %d",sum);
    return 0;
}