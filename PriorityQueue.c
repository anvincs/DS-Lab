#include<stdio.h>
int pqueue[10],front=-1,rear=-1;
void priority_insert(int data)
{
    if(front==-1)
    {
        front=0;
        rear=0;
        pqueue[rear]=data;
        return;
    }
    if(rear==9)
    {
        printf("\nOverflow !!\nCouldn't insert element\n\n");
    }
    else
    {
        for(int i=0;i<=rear;i++)
        {
            if(pqueue[i]>data)
            {
                for(int j=rear+1;j>i;j--)
                {
                    pqueue[j]=pqueue[j-1];
                }
                pqueue[i]=data;
                rear++;
                return;
            }
        }
        rear++;
        pqueue[rear]=data;
    }
}
void priority_delete(int data)
{
    if(rear==-1 || front>rear)
    {
        printf("\nUnderflow !!\n\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            if(pqueue[i]==data)
            {
                for(int j=i;j<rear;j++)
                {
                    pqueue[j]=pqueue[j+1];
                }
                rear--;
                printf("\n%d is removed\n\n",data);
                return;
            }
        }
        printf("\nElement not present in queue\n\n");
    }
}
void display()
{
    if(rear==-1 || front>rear)
    {
        printf("\nEmpty Queue\n\n");
    }
    else
    {
        printf("\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",pqueue[i]);
        }
        printf("\n\n");
    }
}
int main()
{
    int op,data;
    do
    {
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                    printf("Enter the element to be inserted : ");
                    scanf("%d",&data);
                    priority_insert(data);
                    break;
            case 2:
                    printf("Enter the element to be deleted : ");
                    scanf("%d",&data);
                    priority_delete(data);
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