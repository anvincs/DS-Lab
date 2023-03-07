#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp = fopen("name.txt","a");
    fprintf(fp,"\n Manukrishnan");
    fclose(fp);
    return 0;
}