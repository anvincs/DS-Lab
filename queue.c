#include<stdio.h>
int queue[10],front=-1,rear=-1,data;
void enqueue()
{
    if(front=-1)
    {
        front++;
    }
    if(rear==9)
    {
        printf("\nOverflow !!\n\n");
    }
    else
    {
        printf("Enter the element to be added : ");
        scanf("%d",&data);
        rear++;
        queue[rear]=data;
    }
}
void dequeue()
{
    if(front=-1 || front>rear)
    {
        printf("\nUnderflow !!\n\n");
    }
    else
    {
        data=queue[front];
        front++;
        printf("\nThe removed element is %d\n\n",data);
    }
}
void display()
{
    if(front=-1 || front>rear)
    {
        printf("\nEmpty Queue\n\n");
    }
    else
    {
        printf("\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n\n");
    }
}
int main()
{
    int op;
    do
    {
        printf("1.Insert  2.Delete  3.Display  4.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                    enqueue();
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
                    printf("\nInvalid option\n\n");
        }
    } while (op!=4);
    return 0;
}