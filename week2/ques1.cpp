#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findFirstAndLast(int arr[], int n, int x)
{
    int first, last;
    // to store first occurrence
    first = lower_bound(arr, arr + n, x) - arr;
    // to store last occurrence
    last = std::upper_bound(arr, arr + n, x) - arr - 1;
 
    if (first == n) {
        first = -1;
        last = -1;
    }
    return (last-first+1);
}

int main()
{
    int T,n,i,key;
    cin>>T;
    while(T>0)
    {
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        cin>>key;
        int o=findFirstAndLast(arr,n,key);
        if(o==-1)
            cout<<"NOT PRESENT";
        else
        {
            cout<<key<<" -> "<<o;
        }
        --T;
        cout<<"\n";
    }
    return 0;
}