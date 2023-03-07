#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *top = NULL;

void push(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Out of space in memory\n");
        return;
    }
    temp->val=x;
    temp->next=NULL;
    if(top==NULL)
    {
        top=temp;
        return;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack Underflow !!\n");
        return;
    }
    struct node *ptr = top;
    top=top->next;
    printf("%d is removed\n",ptr->val);
    free(ptr);
}

void display()
{
    if(top==NULL)
    {
        printf("Empty Stack\n");
        return;
    }
    struct node *ptr = top;
    while(ptr != NULL)
    {
        printf("%d ",ptr->val);
        ptr=ptr->next;
    }
    printf("\n");
}

int main()
{
    int op,e;
    do
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter the element to push : ");
                scanf("%d",&e);
                push(e);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid option\n");
        }
    } while (op != 4); 
}