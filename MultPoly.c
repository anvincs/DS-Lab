#include<stdio.h>
#include<stdlib.h>

struct polynode
{
    int coef,exp;
    struct polynode* next;
};

void display(struct polynode* ptr)
{
    if(ptr==NULL)
    {
        printf("Empty polynomial\n");
        return;
    }
    while(ptr->next != NULL)
    {
        printf("%dx^%d + ",ptr->coef,ptr->exp);
        ptr=ptr->next;
    }
    printf("%dx^%d\n",ptr->coef,ptr->exp);
}

void insertElement(struct polynode** start,int co,int xp)
{
    struct polynode* temp = (struct polynode*)malloc(sizeof(struct polynode));
    if(temp==NULL)
    {
        printf("Node not created\n");
        return;
    }
    temp->coef=co;
    temp->exp=xp;
    temp->next=NULL;

    if((*start)==NULL)
    {
        (*start)=temp;
        return;
    }
    else
    {
        struct polynode *p ,*prev;
        p=(*start);

        if(xp>p->exp)
        {
            temp->next=p;
            (*start)=temp;
            return;
        }

        while(p->next != NULL  &&  p->exp > xp)
        {
            prev=p;
            p=p->next;
        }

        if(p->exp==xp)
        {
            p->coef+=co;
            free(temp);
            return;
        }
    
        if(p->exp < xp)
        {
            temp->next=p;
            prev->next=temp;
        }
        else if(p->next==NULL)
        {
            p->next=temp;
        }
    }
}

void multiply(struct polynode** poly1,struct polynode** poly2,struct polynode ** polypd)
{
    struct polynode *tp1=(*poly1),*tp2=(*poly2);
    int new_coef,new_exp;
    if(tp1==NULL  ||  tp2==NULL)
    {
        printf("Error.....\n");
        return;
    }
    while(tp1 != NULL)
    {
        while(tp2 != NULL)
        {
            new_coef=tp1->coef*tp2->coef;
            new_exp=tp1->exp+tp2->exp;
            insertElement(&(*polypd),new_coef,new_exp);
            tp2=tp2->next;
        }
        tp2=(*poly2);
        tp1=tp1->next;
    }
}

int main()
{
    struct polynode *p1=NULL,*p2=NULL,*prod=NULL;
    int t1,t2,cf,ep;
    printf("Enter no. of terms in the first polynomial : ");
    scanf("%d",&t1);
    for(int i=0;i<t1;i++)
    {
        printf("Enter the coefficient : ");
        scanf("%d",&cf);
        printf("Enter the exponent : ");
        scanf("%d",&ep);
        insertElement(&p1,cf,ep);
    }

    printf("Enter no. of terms in the second polynomial : ");
    scanf("%d",&t2);
    for(int i=0;i<t2;i++)
    {
        printf("Enter the coefficient : ");
        scanf("%d",&cf);
        printf("Enter the exponent : ");
        scanf("%d",&ep);
        insertElement(&p2,cf,ep);
    }

     printf("The first polynomial is \n");
     display(p1);
     printf("The second polynomial is \n");
     display(p2);

    multiply(&p1,&p2,&prod);
    printf("The product of the polynomials is \n");
    display(prod);

    return 0;
}