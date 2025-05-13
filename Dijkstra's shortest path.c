#include <stdio.h>

//To add a weighted edge.
void addEdge(int ver,int arr[][ver],int x,int y,int w)
{
    arr[x][y]=w;
    arr[y][x]=w;
}

//To perform Dijikstra's algorithm
void Dijkstra(int ver,int arr[][ver], int start)
{
    //Arrays to store cost,shortest distance,Predecessor of each vertex,Visited vertices.
    int cost[ver][ver],dist[ver],pre[ver],visited[ver];
    int count,min,next;

    for (int i=0;i<ver;i++)
    {
        for (int j=0;j<ver;j++)
        {
            if (arr[i][j]==0)
                cost[i][j]=10000;
            else
                cost[i][j]=arr[i][j];
        }    
    }    

    for (int i=0;i<ver;i++)
    {
        dist[i]=cost[start][i];//Distance from start to each vertex.
        pre[i]=start;//Initialising predecessor as the start vertex.
        visited[i]=0;//Initialising all verstices as not visited.
    }

    dist[start]=0;
    visited[start]=1;
    count=1;

    while (count<ver-1) 
    {
        min=10000;
        //To find unvisited vertex with minimum distance.
        for (int i=0;i<ver;i++)
        {
            if (dist[i]<min&&!visited[i]) 
            {
                min=dist[i];
                next=i;
            }
        }    

        visited[next] = 1;

        //Updating distances.
        for (int i=0;i<ver;i++)
        {
            if (!visited[i])
            {
                if (min+cost[next][i]<dist[i]) 
                {
                    dist[i]=min+cost[next][i];
                    pre[i]=next;//Updating the predecessor.
                }
            }    
        }    
        count++;
    }
    
    //To print shortest distance of all the vertices from the start vertex.
    for (int i = 0; i < ver; i++)
    {
        if (i != start) 
        {
            printf("\nDistance from source to %d: %d", i, dist[i]);
        }
    }    
}

//To print the adjacency matrix.
void printAdjMatrix(int ver,int arr[][ver]) 
{
    for (int i=0;i<ver;i++)
    {
        printf("%d: ",i);
        for (int j=0;j<ver;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int ver;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&ver);

    int visited[ver];//Array for visited vertices.
    int adjMatrix[ver][ver];//Adjacency matrix to represent the graph.

    for (int i=0;i<ver;i++)
        for (int j=0;j<ver;j++)
            adjMatrix[i][j] = 0;//Initialize all entries as zero.

    printf("Enter the vertices of an edge and its weight:\n");
    int cont=1;
    while (cont==1)
    {
        int x, y, w;
        scanf("%d %d %d",&x,&y,&w);//Taking edge and weight as input.
        if (x>=ver||y>=ver||x<0||y<0)
        {
            printf("Invalid vertex! Must be between 0 and %d.\n",ver-1);
        }
        else 
        {
            addEdge(ver,adjMatrix,x,y,w);//Adding the taken edge to the graph.
        }
        printf("Do you want to continue? (Yes=1 / No=0): ");
        scanf("%d",&cont);
    }

    printf("\nAdjacency Matrix:\n");
    printAdjMatrix(ver,adjMatrix);//To print the complete graph.

    printf("\nEnter the starting vertex for Dijkstra's algorithm: ");
    int start;
    scanf("%d",&start);//Taking start vertex from the user.

    if (start<0||start>=ver)
    {
        printf("Invalid start vertex.\n");
        return 1;
    }

    printf("\n");
    Dijkstra(ver,adjMatrix,start);//Calling the function to perform Dijkstra's algorithm.

    return 0;
}