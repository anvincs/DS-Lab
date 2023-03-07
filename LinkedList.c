#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *link;
};
struct node *start = NULL;

void display()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\nEmpty List\n\n");
        return;
    }
    else
    {
        ptr=start;
        printf("\n\n");
        while(ptr!=NULL)
        {
            printf("%d->",ptr->value);
            ptr=ptr->link;
        }
        printf("END\n\n");
    }
}
void insert_at_beginning()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of space in memory\n\n");
        return;
    }
    printf("\nEnter the value : ");
    scanf("%d",&temp->value);
    printf("\n");
    if(start==NULL)
    {
        start=temp;
        temp->link=NULL;
    }
    else
    {
        temp->link=start;
        start=temp;    
    }
}
void insert_at_end()
{
    struct node *temp,*ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of space in memory\n\n");
        return;
    }
    printf("\nEnter the value : ");
    scanf("%d",&temp->value);
    printf("\n");
    if(start==NULL)
    {
        start=temp;
        temp->link=NULL;
    }
    else
    {
        ptr=start; 
        while(ptr->link != NULL)
        {
            ptr=ptr->link;
        }
        ptr->link = temp;
        temp->link = NULL;
    }
}
void insert_at_pos()
{
    struct node* temp,*ptr;
    int i,pos;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nOut of space in memory\n\n");
        return;
    }
    printf("\nEnter position of new node :");
    scanf("%d",&pos);
    printf("\nEnter the value :");
    scanf("%d",&temp->value);
    printf("\n");

    if(pos==1)
    {
        temp->link=start;
        start=temp;
    }
    else
    {
        ptr=start;
        for(i=1;i<pos-1;i++)
        {
            ptr=ptr->link;
            if(ptr==NULL)
            {
                printf("\nPosition not found\n\n");
                return;
            }
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
}
void delete_from_beginning()
{
    struct node* ptr;
    if(start==NULL)
    {
        printf("\nEmpty List\n\n");
        return;
    }
    else
    {
        ptr=start;
        start=ptr->link;
        printf("\n%d is removed\n\n",ptr->value);
        free(ptr);
    }
}
void delete_from_end()
{
    struct node *temp,*ptr;
    if(start==NULL)
    {
        printf("\nEmpty List\n\n");
        return;
    }
    else if(start->link == NULL)
    {
        ptr=start;
        start=NULL;
        printf("\n%d is removed\n\n",ptr->value);
        free(ptr);
    }
    else
    {
        ptr=start;
        while(ptr->link != NULL)
        {
            temp=ptr;
            ptr=ptr->link;
        }
        temp->link=NULL;
        printf("\n%d is removed\n\n",ptr->value);
        free(ptr);
    }
}
void delete_from_pos()
{
    struct node *temp,*ptr;
    int i,pos;
    if(start==NULL)
    {
         printf("\nEmpty List\n\n");
        return;
    }
    printf("\nEnter the position of node to be deleted :");
    scanf("%d",&pos);
    if(pos==1)
    {
        delete_from_beginning();
        return;
    }
    else
    {
        ptr=start;
        for(i=1;i<pos;i++)
        {
            temp=ptr;
            ptr=ptr->link;
            if(ptr==NULL)
            {
                printf("\nPosition not found\n\n");
                return;
            }
        }
        temp->link=ptr->link;
        printf("\n%d is removed\n",ptr->value);
        free(ptr);
    }
}
int main()
{
    int op;
    do
    {
        printf("1.Insert at first\n2.Insert at end\n3.Insert at position\n4.Delete from first\n5.Delete from end\n6.Delete from position\n7.Display\n8.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                    insert_at_beginning();
                    break;
            case 2:
                    insert_at_end();
                    break;
            case 3:
                    insert_at_pos();
                    break;
            case 4:
                    delete_from_beginning();
                    break;
            case 5:
                    delete_from_end();
                    break;
            case 6:
                    delete_from_pos();
                    break;
            case 7:
                    display();
                    break;
            case 8:
                    break;
            default:
                    printf("Invalid option\n");
        }
    } while (op != 8);
    
    return 0;
}