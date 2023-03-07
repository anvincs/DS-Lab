#include<stdio.h>
int stack[5],top=-1,data;
void push()
{
    if(top==4)
    {
        printf("\n\nStack Overflow !!\n\n");
        return;
    }
    printf("Enter number to push : ");
    scanf("%d",&data);
    top++;
    stack[top]=data;
}
void pop()
{
    if(top==-1)
    {
        printf("\n\nStack Underflow !! \n\n");
    }
    else
    {
        int data = stack[top];
        top--;
        printf("The removed element is %d \n",data);
    }
}
void display()
{
    if(top==-1)
    {
        printf("\nEmpty Stack \n\n");
    }
    else
    {
        printf("\n");
        for(int i=0;i<=top;i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n\n");
    }
}
int main()
{
    int op;
    do
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1 :
                    push();
                    break;
            case 2 :
                    pop();
                    break;
            case 3 :
                    display();
                    break;
            case 4 :
                    break;
            default :
                    printf("Invalid option\n");
        }
    }while(op!=4);
    return 0;
}