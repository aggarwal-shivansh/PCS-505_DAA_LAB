#include<iostream>
using namespace std;
int main()
{
    int T,n,key,f=0,i,mid,low,high;
    cin>>T;
    while(T>0)
    {
        cin>>n;         //input the size of array
        int arr[n];
        for(i=0;i<n;i++)        //input n no of elements
            cin>>arr[i];
        cin>>key;       //input key element

        //searching algorithm BINARY SEARCH

        low = 0;
        high = n;
        
        while(low<high)
        {
            mid=low+(high-low)/2;
            if(key==arr[mid])
            {
                f=1;
                break;
            }
            else if(key>arr[mid])
                low=mid+1;
            else if(key<arr[mid])
                high=mid-1;
        }
        if(f==0)
            cout<<"Not Present";
        else
            cout<<"Present "<<mid+1;
        --T;
        cout<<"\n";
    }
    return 0;
}