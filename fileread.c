#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    char line[100];
    FILE *fp=fopen("name.txt","r");
    printf("Enter no.of lines : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        fgets(line,100,fp);
        printf("%s",line);
    }
    fclose(fp);
    return 0;
}