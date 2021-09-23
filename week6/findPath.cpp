#include<iostream>
#include<list>
using namespace std;
class Graph
{
    int V;
    list<int>* adj;

    public: 
        Graph(int V);
        void addEdge(int v,int w);
        bool isReachable(int s,int d);
};
Graph::Graph(int V)
{
    this->V=V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(V);
}
bool Graph::isReachable(int s, int d)
{
    if(s==d)
        return true;
    bool* visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    list<int> queue;  // queue for BFS

    visited[s]=true;
    queue.push_back(s);

    list<int>::iterator i; //get neighbours of a vertex
    while(!queue.empty())
    {
        s=queue.front();
        queue.pop_front();


        for(i=adj[s].begin();i!=adj[s].end();++i)
        {
            if(*i==d)
                return true;
            
            if(!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }
    return false;
}
int main()
{
    int i,j,V,u,v;
    cin>>V;
    Graph g(V);
    int arr[V][V];
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            cin>>arr[i][j];
    cin>>u;
    cin>>v;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if(arr[i][j]==1)
                g.addEdge(i,j);
        }
    }

    if(g.isReachable(u,v))
        cout<<"YES PATH EXIST. ";
    else
        cout<<"NO! THERE IS NO PATH.";

    return 0;
}