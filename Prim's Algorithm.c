#include <stdio.h>
#include <limits.h>

//To add a weighted edge.
void addEdge(int ver,int arr[][ver],int x,int y,int w)
{
    arr[x][y]=w;
    arr[y][x]=w;
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

//Prim's Algorithm to find MST.
void Prims(int ver,int arr[][ver],int visited[ver],int start) 
{
    for (int i=0;i<ver;i++)
        visited[i]=0;//Initializing all vertices as not visited.

    visited[start]=1;//Start from the given vertex.
    int edgeCount=0;
    int totalCost=0;

    printf("Edges in the Minimum Spanning Tree:\n");

    while (edgeCount<ver-1)//Since number of edges in MST cannot exceed no.of vertices-1.
    {
        int min=INT_MAX;
        int u=-1,v=-1;

        for (int i=0;i<ver;i++)
        {
            if (visited[i]) 
            {
                for (int j=0;j<ver;j++)//To check all adjacent vertices of visited vertex i.
                {
                    if (!visited[j]&&arr[i][j]&&arr[i][j]<min)//If j is unvisited and the edge i-j has smaller weight.
                    {
                        min=arr[i][j];//To update minimum weight.
                        u=i;
                        v=j;
                    }
                }
            }
        }

        if (u!=-1&&v!=-1)//Include the edge in MST if it is valid.
        {
            printf("%d - %d (weight %d)\n",u,v,arr[u][v]);
            visited[v]=1;
            totalCost+=arr[u][v];//Adding weights of all the valid edges in the MST.
            edgeCount++;
        }
    }

    printf("Total cost of MST: %d\n",totalCost);
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

    printf("\nEnter the starting vertex for Prim's algorithm: ");
    int start;
    scanf("%d",&start);//Taking start vertex from the user.

    if (start<0||start>=ver)
    {
        printf("Invalid start vertex.\n");
        return 1;
    }

    printf("\n");
    Prims(ver,adjMatrix,visited,start);//Calling the function to perform Prim's algorithm.

    return 0;
}