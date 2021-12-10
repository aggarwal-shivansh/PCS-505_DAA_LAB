#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool compare(pair<pair<float,int>,pair<int,int>> a,pair<pair<float,int>,pair<int,int>> b )
{
    return a.first.first>b.first.first;
}
int main()
{
    int N,w,v,i;
    cin>>N;
    int weight[N];
    int val[N];
    for(i=0;i<N;i++)
        cin>>weight[i];
    for(i=0;i<N;i++)
        cin>>val[i];
    cin>>w;
    vector<pair<pair<float,int>,pair<int,int>>> sack;
    vector<pair<int,int>> res;
    for(i=0;i<N;i++)
    {
        sack.push_back(make_pair(make_pair((val[i]/(float)weight[i]),i+1),make_pair(weight[i],val[i])));
    }

    sort(sack.begin(),sack.end(),compare);

    float profit = 0.0;
    for(i=0;i<N;i++)
    {
        if(sack[i].second.first<w)
        {
            profit += sack[i].first.first*sack[i].second.first; 
            w-=sack[i].second.first;
            res.push_back(make_pair(sack[i].first.second,sack[i].second.first));

        }
        else
        {
            profit += sack[i].first.first*(w);
            res.push_back(make_pair(sack[i].first.second,w));
            break; 
        }
    }
    cout<<"PROFIT : "<<profit<<"\n";
    for(i=0;i<res.size();i++)
        cout<<res[i].first<<" -> "<<res[i].second<<"\n";

    return 0;
}