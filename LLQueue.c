#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *front = NULL,*rear=NULL;

void enqueue(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Out of space in memory\n");
        return;
    }
    temp->val=x;
    temp->next=NULL;
    if(rear==NULL)
    {
        front=temp;
        rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Queue Underflow !!");
        return;
    }
    struct node *ptr = front;
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
        printf("%d is removed\n",ptr->val);
        free(ptr);
        return;
    }
    else
    {
        front=front->next;
        printf("%d is removed\n",ptr->val);
        free(ptr);
        return;
    }
}

void display()
{
    struct node *ptr = front;
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
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter the element to insert : ");
                scanf("%d",&e);
                enqueue(e);
                break;
            case 2:
                dequeue();
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