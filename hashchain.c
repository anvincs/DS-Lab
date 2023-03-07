#include<stdio.h>
#include<stdlib.h>
struct list
{
  int val; 
  struct list *next;
};
struct list *chain[10];

void addElement(struct list** start,int x)
{
  struct list *ptr = (*start);
  struct list *temp = (struct list*)malloc(sizeof(struct list));
  temp->val=x;
  temp->next=NULL;

  if(ptr==NULL)
  {
    (*start)=temp;
    return;
  }
  while(ptr->next != NULL)
  {
    ptr=ptr->next;
  }
  ptr->next=temp;
}

int hashkey(int x)
{
  return x%10;
}

void display(struct list *ptr)
{
  while(ptr != NULL)
  {
    printf("%d->",ptr->val);
    ptr=ptr->next;
  }
  printf("NULL");
}

void find(struct list *ptr,int x)
{
  while (ptr != NULL)
  {
    if(ptr->val==x)
    {
      printf("Element is present\n");
      return;
    }
    ptr=ptr->next;
  }
  printf("Element not found\n");
}

int main()
{
  int n,e,hk,fn;
  for(int i=0;i<10;i++)
  {
    chain[i]=NULL;
  }
  printf("Enter no. of elements to insert : ");
  scanf("%d",&n);
  printf("Enter %d numbers\n",n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&e);
    hk = hashkey(e);
    addElement(&chain[hk],e);
  }
  
  for (int i = 0; i < 10; i++)
  {
    printf("chain[%d]-->",i);
    display(chain[i]);
    printf("\n");
  }
  printf("\n");
  return 0;
}