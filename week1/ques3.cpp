#include<iostream>
#include<cmath>
using namespace std;
int jump(int arr[],int n,int key)
{
    int jump,prev,steps;
    jump = sqrt(n);
    steps = jump;
    prev = 0;

    while(arr[min(steps, n)-1] < key)
    {
        prev = steps;
        steps+= jump;
        if(prev>=n)
            return -1;
    }
    while(arr[prev]<key)
    {
        prev+=1;
        if(prev==min(steps,n))
            return -1;
    }
    if(arr[prev]==key)
        return prev;
    return -1;
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

        //searching algorithm JUMP SEARCH

        if(jump(arr,n,key) > 0)
            cout<<"PRESENT";
        else
            cout<<"NOT PRESENT";
        --T;
        cout<<"\n";
    }
    return 0;
}
