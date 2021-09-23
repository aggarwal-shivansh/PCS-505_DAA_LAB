#include<iostream>
using namespace std;

int main()
{
    int n,m,i,j,k,f=0;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)        //input array 1st
        cin>>arr[i];
    cin>>m;
    int brr[m];
    for(i=0;i<m;i++)        //input array 2nd
        cin>>brr[i];
    i=0,j=0;
    while(i<n && j<m)
    {
        if(arr[i]<brr[j])
            ++i;
        else if(arr[i]>brr[j])
            ++j;
        else
        {
            ++i;
            ++j;
            cout<<brr[j]<<" ";
            f=1;
        }
    }
    if(f==0)
        cout<<"NO COMMON ELEMENTS FOUND";
    return 0;
}