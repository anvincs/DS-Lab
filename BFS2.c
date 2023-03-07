#include<stdio.h>
int queue[10],front=-1,rear=-1,data;
int graph[7][7]={0};
int visited[10]={0};
int isEmpty()
{
    if(front==-1)
    {
        return 1;
    }
    return 0;
}
void enqueue(int x)
{
   if(rear==9)
   {
    printf("Overflow !!\n");
    return;
   }
   if(front==-1)
   {
    front++;
   }
   rear++;
   queue[rear]=x;
}
int dequeue()
{
    if(isEmpty())
    {
        printf("\nUnderflow !!\n\n");
    }
    else if(front==rear)
    {
        data=queue[front];
        front=-1;
        rear=-1;
        return data;
    }
    else
    {
        data=queue[front];
        front++;
        return data;
    }
}
void addEdge(int v1,int v2)
{
    graph[v1][v2]=1;
    graph[v2][v1]=1;
}
void bfs(int start)
{
     printf("%d ",start);
    visited[start]=1;
    enqueue(start);
    while(!isEmpty())
    {
        int node = dequeue();
        for(int j=0;j<7;j++)
        {
            if(graph[node][j]==1 && visited[j]==0)
            {
                printf("%d ",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}

int main()
{
    int e1,e2,op,d;
    do
    {
        printf("1.Create Edge\n2.BFS\n3.Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter vertexes :");
                scanf("%d%d",&e1,&e2);
                addEdge(e1,e2);
                break;
            case 2:
                bfs(0);
                printf("\n");
                break;
            case 3:
                break;
            default:
                printf("Invalid option\n");
        }
    } while (op != 3);
    
    return 0;
}