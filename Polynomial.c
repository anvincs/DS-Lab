#include<stdio.h>
typedef struct 
{
    int coef;
    int exp;
}poly;
int main()
{
    poly a[20],b[20],c[20];
    int n1,n2,j=0,k=0,q=0,z=0;
    printf("Enter no. of terms in first polynomial : ");
    scanf("%d",&n1);
    printf("Enter pair of coefficient and exponent\n");
    for(int i=0;i<n1;i++)
    {
        scanf("%d%d",&a[i].coef,&a[i].exp);
    }
    printf("Enter no. of terms in second polynomial : ");
    scanf("%d",&n2);
    printf("Enter pair of coefficient and exponent\n");
    for(int i=0;i<n2;i++)
    {
        scanf("%d%d",&b[i].coef,&b[i].exp);
    }

    while(1)
    {
        if(a[j].exp == b[k].exp)
        {
            c[q].coef = a[j].coef + b[k].coef;
            c[q].exp = a[j].exp;;
            j++;
            k++;
            q++;
        }
        else if(a[j].exp > b[k].exp)
        {
            c[q].coef = a[j].coef;
            c[q].exp = a[j].exp;
            q++;
            j++;
        }
        else
        {
            c[q].coef = b[k].coef;
            c[q].exp = b[k].exp;
            q++;
            k++;
        }

        if(j == n1)
        {
            while (k != n2)
            {
                c[q].coef = b[k].coef;
                c[q].exp = b[k].exp;
                q++;
                k++;
            }
            break;
        }

        if(k == n2)
        {
            while(j != n1)
            {
                c[q].coef = a[j].coef;
                c[q].exp = a[j].exp;
                q++;
                j++;
            }
            break;
        }
    }

    printf("The first polynomial is \n");
    for(int i=0;i<n1-1;i++)
    {
        printf("%dx^%d + ",a[i].coef,a[i].exp);
    }
    printf("%dx^%d\n",a[n1-1].coef,a[n1-1].exp);

    printf("The second polynomial is \n");
    for(int i=0;i<n2-1;i++)
    {
        printf("%dx^%d + ",b[i].coef,b[i].exp);
    }
    printf("%dx^%d\n",b[n2-1].coef,b[n2-1].exp);

    printf("The resultant polynomial is\n");
    for(int i=0;i<q-1;i++)
    {
        printf("%dx^%d + ",c[i].coef,c[i].exp);
    }
    printf("%dx^%d\n",c[q-1].coef,c[q-1].exp);

    return 0;
}