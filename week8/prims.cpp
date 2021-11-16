#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minset(int weight[],bool visit[],int V)
{
    int min = INT_MAX,minindex;
    for(int i=0;i<V;i++)
    {
        if(visit[i]==false&&weight[i]<min)
        {
            min=weight[i];
            minindex=i;
        }
    }
    return minindex;
}

void prims(int **graph , int V)
{
    int parent[V];
    int weight[V];
    bool visit[V];
    int s=0;
    for(int i=0;i<V;i++)
    {
        visit[i]=false;
        weight[i]=INT_MAX;
        parent[i]=-1;
    }

    weight[0]=0;
    
    for(int j=0;j<V-1;j++)
    {
        int u = minset(weight,visit,V);
        visit[u]=true;

        for(int v=0;v<V;v++)
        {
            if(graph[u][v]&&visit[v]==false&&graph[u][v]<weight[v])
            {
                parent[v]=u;
                weight[v]=graph[u][v];
            }
        }

    }

    //print the result
    for(int i=0;i<V;i++)
        s+=weight[i];

    cout<<"MINIMUM SPANNING WEIGHT: "<<s;
}

int main()
{
    int V,i,j;
    cin>>V;
    int **graph;
    graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; ++i)
        graph[i] = (int *)malloc(V * sizeof(int));
    for(i=0;i<V;i++)
    for(j=0;j<V;j++)
        cin>>graph[i][j];

    prims(graph,V);

    return 0;

}