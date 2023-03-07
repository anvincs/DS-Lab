#include<stdio.h>
#include<string.h>
int main()
{
    int i=0,k=0,l=0;
    char str[25],rev[25];
    printf("Enter a string \n");
    scanf("%s",str);
    while(str[i]!='\0')
    {
        i++;
        l++;
    }
    for(int j=l-1;j>=0;j--)
    {
        rev[k]=str[j];
        k++;
    }
    if(strcmp(rev,str)==0)
    {
        printf("Palindrome word \n");
    }
    else
    {
        printf("Not Palindrome word \n");
    }
    return 0;
}