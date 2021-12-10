/*SHIVANSH AGGARWAL     2014860*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<pair<pair<int,int>,int>> jobs;
    vector<int> selected;
    int time[N];
    int deadline[N];
    for(int i=0;i<N;i++)
        cin>>time[i];
    for(int i=0;i<N;i++)
        cin>>deadline[i];
    for(int i=0;i<N;i++)
        jobs.push_back(make_pair(make_pair(deadline[i],time[i]),i+1));

    sort(jobs.begin(),jobs.end());

    int max=0;
    for(int i=0;i<N;i++)
    {
        if(jobs[i].first.first>max)
            max=jobs[i].first.first;
    }

    int fill[max],visited[max]={0};
    int c=0;
    for (int i = 0; i < max; ++i)
        fill[i] = i + 1;
    cout<<"SELECTED TASK NUMBERS :";
    for(int i=0;i<N;i++)
    {
        int du = jobs[i].first.second, de = jobs[i].first.first - 1;
        if (fill[de] >= du)
        {
            for (int j =  max- 1; j > de; --j)
                fill[j] -= du;
            int x = 0;
            while (x != du)
            {
                fill[de] -= du - x;
                if (fill[de] > 0 && !visited[de])
                    ++x;
                --de;
            }
            ++c;
            selected.push_back(jobs[i].second);
            visited[de] = 1;
        }
    }
    cout << "Max Number of Tasks: " << c << endl;
    cout << "Selected Task Numbers: ";
    cout << selected[0];
    int l = selected.size();
    for (int i = 1; i < l; ++i)
    {
        cout << ", " << selected[i];
    }
    return 0;
}