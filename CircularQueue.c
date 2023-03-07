#include<stdio.h>
#define SIZE 5
int cq[SIZE];
int front=-1,rear=-1;
int isEmpty()
{
    if(front==-1)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    if(((rear+1)%SIZE) == front)
    {
        return 1;
    }
    return 0;
}
void insert(int val)
{
    if(isFull()==1)
    {
        printf("\nOverflow !!\n\n");
        return;
    }
    if(rear==-1)
    {
        front++;
        rear++;
        cq[rear]=val;
        return;
    }
    else
    {
        rear=(rear+1)%SIZE;
        cq[rear]=val;
    }
}
void delete()
{
    if(isEmpty()==1)
    {
        printf("\nUnderflow !!\n\n");
        return;
    }
    int val;
    if(front==rear)
    {
        val=cq[front];
        front=-1;
        rear=-1;
    }
    else
    {
        val=cq[front];
        front=(front+1)%SIZE;
    }
    printf("%d is removed\n",val);
}
void display()
{
     if(isEmpty())
    {
        printf("\nEmpty Queue\n\n");
        return;
    }
    else
    {
        printf("\nQUEUE STATUS\n");
        int i=front;
        while(1)
        {
            printf("%d ",cq[i]);
            if(i==rear)
            {
                break;
            }
            i=(i+1)%SIZE;
        }
        printf("\n\n");
    }
}
int main()
{
    int op,x;
    do
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                    printf("Enter value to be inserted: ");
                    scanf("%d",&x);
                    insert(x);
                    break;
            case 2:
                    delete();
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    break;
            default:
                    printf("\nInvalid option\n\n");
        }
    } while (op!=4);
    return 0;
}