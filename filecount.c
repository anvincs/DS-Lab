#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char fname[50];
    int ch;
    int nl=0,nw=0,nc=0;
    printf("Enter the file name : ");
    scanf("%s",fname);
    fp=fopen(fname,"r");
    if(fp==NULL)
    {
        printf("Error opening file \n");
        exit(-1);
    }
    ch=getc(fp);
    while(ch!=EOF)
    {
        if(ch=='\n')
        {
            nl++;
        }
        else if(ch==' ')
        {
            nw++;
        }
        else
        {
            nc++;
        }
        ch=getc(fp);
    }
    fclose(fp);
    printf("No.of lines=%d No.of words=%d No.of characters=%d",nl+1,nl+1+nw,nc);
    fp=fopen("result.txt","w");
    fprintf(fp,"No.of lines=%d No.of words=%d No.of characters=%d",nl+1,nl+1+nw,nc);
    fclose(fp);
    return 0;
}