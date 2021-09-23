#include<iostream>
using namespace std;

int linear(int arr[],int index, int n,int key)
{
    int i;
    for(i= index;i<n;i++)
    {
        if(key==arr[i])
            return i;
    }
    return -1;
}

int binary(int arr[],int low,int high,int key)
{
    if(low<=high)
    {
        int mid=low+(high-low)/2;

        if(key==arr[mid])
            return mid;
        else if(key>arr[mid])
            return binary(arr,mid+1,high,key);
        else
            return binary(arr,low,mid-1,key);
    }
    else
        return -1;
}

int exponential(int arr[],int n,int key)
{
    int i;
    if(arr[0]==key)
        return 0;
    i=1;
    while(i<n && arr[i]<key)
    {
        i=i*2;
    }
    return linear(arr,(int)i/2,n,key);
}

int main()
{
    int T,n,key,i;
    cin>>T;
    while(T>0)
    {
        cin>>n;         //input the size of array
        int arr[n];
        for(i=0;i<n;i++)        //input n no of elements
            cin>>arr[i];
        cin>>key;       //input key element

        //searching algorithm EXPONENTIAL SEARCH

        if(exponential(arr,n,key) > 0)
            cout<<"PRESENT";
        else
            cout<<"NOT PRESENT";
        --T;
        cout<<"\n";
    }
    return 0;
}