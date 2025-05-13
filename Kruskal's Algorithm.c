#include<stdio.h>
#include<limits.h>

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

//Kruskal's Algorithm to find MST.
void Kruskal(int ver,int arr[][ver])
{
    int parent[ver];//Parent array to track connected edges.
    for(int i=0;i<ver;i++)
        parent[i]=i;//Initialising each vertex's parent to itself.

    int edgeCount=0;
    int totalCost=0;

    printf("Edges in the MST:\n");

    while(edgeCount<ver-1)//Since number of edges in MST cannot exceed no.of vertices-1.
    {
        int min=INT_MAX;
        int a=-1,b=-1;

        for(int i=0;i<ver;i++)//To find the least weight edge.
        {
            for(int j=i+1;j<ver;j++)
            {
                if(arr[i][j])//If edge exists
                {
                    int u=i;
                    while(u!=parent[u])
                        u=parent[u];
 
                    int v=j;
                    while(v!=parent[v])
                        v=parent[v];

                    if(u!=v&&arr[i][j]<min)//If edge exists and its weight is smaller.
                    {
                        min=arr[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        if(a!=-1&&b!=-1)//Include the edge in MST if it is valid.
        {
            int u=a;
            while(u!=parent[u])
                u=parent[u];

            int v=b;
            while(v!=parent[v])
                v=parent[v];

            parent[u]=v;

            printf("%d - %d  weight: %d\n",a,b,arr[a][b]);
            totalCost+=arr[a][b];//Adding weights of all the valid edges in the MST.
            edgeCount++;
        }
    }

    printf("Total cost of MST: %d\n",totalCost);
}

int main()
{
    printf("Enter the number of vertices in the graph: ");
    int ver;
    scanf("%d",&ver);
    int adjMatrix[ver][ver];//Adjacency matrix to represent the graph.
    for(int i=0;i<ver;i++)
        for(int j=0;j<ver;j++)
            adjMatrix[i][j]=0;//Initialize all entries as zero.
    
    printf("Enter the vertices of an edge,weights: \n");
    int cont=1;
    while(cont==1)
    {
        int x,y,w;
        scanf(" %d %d %d",&x,&y,&w);//Taking edge and weight as input.
        addEdge(ver,adjMatrix,x,y,w);//Adding the taken edge to the graph.
        printf("Do you want to continue?(Yes=1/No=0) ");
        scanf("%d",&cont);
    }
    printf("\n");
    printAdjMatrix(ver,adjMatrix);//To print the complete graph.
    printf("\n");
    Kruskal(ver, adjMatrix);//Calling the function to perform Kruskal's algorithm.
    return 0;
}