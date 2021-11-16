#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector <pair<int,pair<int,int>>> viii;

int find(int u, int *parent)
{
    if(parent[u]<0)
        return u;
    return find(parent[u],parent);
    /*if (u == parent[u])
        return u;
    else{
            return find( parent[u],parent);
        }*/
    
}

void unionbyweight(int u,int v,int *parent)
{
    int pu = find(u,parent);
    int pv = find(v,parent);

    if(pu!=pv)
    {
        if(parent[pu]< parent[pv])
        {
            parent[pu]+=parent[pv];
            parent[pv]=pu;
        }
        else
        {
            parent[pv]+=parent[pu];
            parent[pu]=pv;
        }
    }
     //parent[u] = parent[v];
}

viii kruskuls(viii g,int V)
{
    viii res;
    int s,d,w,i;

    int parents[V];
    for(i=0;i<V;i++)
        parents[i]=-1; 
    

    sort(g.begin(),g.end());        //sorting the graph on basics of weight.

    int E=g.size();

    for(i=0;i<E;i++)
    {
        w=g[i].first;               //weight
        s=g[i].second.first;        //source
        d=g[i].second.second;       //destination

        if(find(s,parents)!=find(d,parents))
        {
            
            res.push_back(g[i]);
            unionbyweight(s,d,parents);
        }
    }
    return res;
}

int main()
{
    int V,E,s,d,w;
    viii g,res;
    cout<<"ENTER NO. OF VERTICES ";
    cin>>V;
    cout<<"ENTER EDGES ";
    cin>>E;
    for(int i=0;i<E;i++)
    {
        cin>>s>>d>>w;
        g.push_back(make_pair(w,make_pair(s,d)));
    }

    res=kruskuls(g,V);

    int sum=0;
    cout<<"SOURCE"<<" "<<"DESTINATION"<<endl;
    for(int i=0;i<res.size();i++)
    {
        int w=res[i].first;
        cout<<res[i].second.first<<"-->"<<res[i].second.second<<endl;
        sum+=w;
    }
    cout<<"SUM IS : "<<sum;
}

/*
0 5 3
5 4 6
4 3 9
1 4 5
0 1 1
1 5 2
2 4 7
1 2 4
2 3 8*/