#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp=fopen("name.txt","w");
    fprintf(fp,"Anvin.C.Shaju\nSankarjith\nEzbon P.J");
    fclose(fp);
    return 0;
}