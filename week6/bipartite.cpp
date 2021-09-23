#include<iostream>
#include<queue>
using namespace std;
bool isBipartite(int **G,int src,int V)
{
    int color[V];
    for(int i=0;i<V;i++)
        color[i]=-1;

    //assign st color to source
    color[src]=1;

    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if (G[u][u] == 1)
        return false;
        for (int v = 0; v < V; ++v)
        {
            if (G[u][v] && color[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (G[u][v] && color[v] == color[u])
                return false;
        }
    }
    return true;
}
int main()
{
    int V;
    cin>>V;
    int **G;
    G=(int **)malloc(V*sizeof(int *));
    for(int i=0;i<V;i++)
    G[i]=(int *)malloc(V*sizeof(int));  
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin>>G[i][j];

    if(isBipartite(G,0,V))
        cout<<"YES IT IS.";
    else
        cout<<"NO IT'S NOT BIPARTITE";
    return 0;
}