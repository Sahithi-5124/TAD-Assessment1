#include <stdio.h>
#define size 50//Defining maximum size for the queue.
int queue[size];
int front=-1,rear=-1;

//To add an edge in the graph.
void addEdge(int ver,int arr[][ver],int x,int y)
{
    arr[x][y]=1;
    arr[y][x]=1;
}

//To enqueue an element into the queue.
void enqueue(int x,int ver)
{
    if(rear==ver-1)
        printf("Queue is full");//To check if queue is full.
    else
    {
        if(front==-1)//If queue is empty.
            front=0;
        rear++;
        queue[rear]=x;//Inserting the element.
    }    
}

//To dequeue an element from the queue.
int dequeue()
{
    if(front==-1||front>rear)//Checking if queue is empty
        return -1;
    else
    {
        return queue[front++];//Returning and removing the front element.
    }
}

//DFS function.
void dfs(int ver,int arr[][ver],int start,int visited[ver])
{
    printf("%d ",start);
    visited[start]=1;//Marking the current vertex as visited.

    for(int i=0;i<ver;i++)
    {
        if(arr[start][i]==1&&!visited[i])
            dfs(ver,arr,i,visited);//Recursive call.
    }
}

//To print the adjacency matrix.
void printAdjMatrix(int ver,int arr[][ver])
{
    for(int i=0;i<ver;i++)
    {
        printf("%d: ",i);
        for(int j=0;j<ver;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
}

int main()
{
    printf("Enter the number of vertices in the graph: ");
    int ver;
    scanf("%d",&ver);
    int visited[ver];//Array for visited vertices.
    for(int i=0;i<ver;i++)
        visited[i]=0;
    int adjMatrix[ver][ver];//Adjacency matrix to represent the graph.
    for(int i=0;i<ver;i++)
        for(int j=0;j<ver;j++)
            adjMatrix[i][j]=0;//Initialize all entries as zero.

    printf("Enter the vertices of an edge: \n");
    int cont=1;
    while(cont==1)
    {
        int x,y;
        scanf(" %d %d",&x,&y);//Take input edge from the user.
        addEdge(ver,adjMatrix,x,y);//Add edge to the adjacency matrix.
        printf("Do you want to continue?(Yes=1/No=0) ");
        scanf("%d",&cont);
    }
    printf("\n");
    printAdjMatrix(ver,adjMatrix);//Print complete Adjacency Matrix.
    printf("\n");
    printf("Enter the starting vertex: ");
    int start;
    scanf("%d",&start);
    printf("\nDFS: ");
    dfs(ver,adjMatrix,start,visited);//To call the DFS traversal function.
}