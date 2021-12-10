/*SHIVANSH AGGARWAL     2014860*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<pair<int,int>> act;
    int start[N],end[N];
    for(int i=0;i<N;i++)
        cin>>start[i];
    for(int i=0;i<N;i++)
        cin>>end[i];

    for(int i=0;i<N;i++)
        act.push_back(make_pair(end[i],start[i]));

    sort(act.begin(),act.end());

    int curr=-1,c=0;
    cout<<"LIST OF ACTIVITIES : ";
    for (int i = 0; i < N; i++)
    {
       if(act[i].second>curr)
       {
           ++c;
           curr=act[i].first;
           cout<<i+1<<",";
       }
    }
    cout<<"\n NO. OF NON CONFLICTING ACTIVITIES : "<<c;
    return 0;
}