#include<stdio.h>
#define MAXSIZE 5
int dque[MAXSIZE];
int front=-1,rear=-1;
void insert_in_front(int val)
{
    if(front==0 && rear==MAXSIZE-1)
    {
        printf("\nQueue Overflow !!\n\n");
        return;
    }
    else if(front==-1)
    {
        front++;
        rear++;
        dque[front]=val;
    }
    else if (front>0)
    {
        front--;
        dque[front]=val;
    }
    else
    {
        for (int i = rear; i >= 0; i--)
        {
            dque[i+1]=dque[i];
        }
        dque[front]=val;
        rear++;
    }
}
void insert_in_rear(int val)
{
    if(front==0 && rear==MAXSIZE-1)
    {
        printf("\nQueue Overflow !!\n\n");
        return;
    }
    else if(rear==-1)
    {
        front++;
        rear++;
        dque[rear]=val;
    }
    else if(rear<MAXSIZE-1)
    {
        rear++;
        dque[rear]=val;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            dque[i-1]=dque[i];
        }
        dque[rear]=val;
        front--;
    }
}
void delete_from_front()
{
    if(front==-1 || front>rear)
    {
        printf("\nQueue Underflow !!\n\n");
        return;
    }
    else
    {
        int data=dque[front];
        front++;
        printf("\n%d is removed\n\n",data);
    }
}
void delete_from_rear()
{
     if(rear==-1 || front>rear)
    {
        printf("\nQueue Underflow !!\n\n");
        return;
    }
    else
    {
        int data=dque[rear];
        rear--;
        printf("\n%d is removed\n\n",data);
    }
}
void display()
{
    if(front==-1 || front>rear)
    {
        printf("\nEmpty Queue\n\n");
        return;
    }
    printf("\nQUEUE STATUS\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",dque[i]);
    }
    printf("\n\n");
}
int main()
{
    int op,data;
    do
    {
        printf("1.Insert from front\n2.Insert from rear\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                    printf("Enter the element to be inserted : ");
                    scanf("%d",&data);
                    insert_in_front(data);
                    break;
            case 2:
                    printf("Enter the element to be inserted : ");
                    scanf("%d",&data);
                    insert_in_rear(data);
                    break;
            case 3:
                    delete_from_front();
                    break;
            case 4:
                    delete_from_rear();
                    break;
            case 5:
                    display();
                    break;
            case 6:
                    break;
            default:
                    printf("\nInvalid option\n\n");
        }
    } while (op!=6);
    return 0;
}