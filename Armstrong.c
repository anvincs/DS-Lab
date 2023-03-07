#include<stdio.h>
#include<math.h>
int main()
{
    int n,rem,sum=0,digits=0;
    printf("Enter a natural number \n");
    scanf("%d",&n);
    int on=n;
    while(n>0)
    {
        n=n/10;
        digits++;
    }
    n=on;
    while (n>0)
    {
        rem=n%10;
        sum+=pow(rem,digits);
        n=n/10;
    }
    if(sum==on)
    {
        printf("Armstrong number \n");
    }
    else
    {
        printf("Not Armstrong number \n");
    }
    return 0;
}