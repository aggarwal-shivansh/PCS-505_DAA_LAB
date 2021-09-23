#include<iostream>
using namespace std;
int main()
{
    int T,n,key,f=0,i;
    cin>>T;
    while(T>0)
    {
        cin>>n;         //input the size of array
        int arr[n];
        for(i=0;i<n;i++)        //input n no of elements
            cin>>arr[i];
        cin>>key;       //input key element

        //searching algorithm

        for(i=0;i<n;i++)       //LINEAR SEARCH
        {
            if(key==arr[i])
            {
                
                f=1;
                break;
            }
        }
        if(f==1)
            cout<<"Present "<<i+1;
        else
            cout<<"Not Present";
        cout<<"\n";
        --T;
    }
    return 0;
}
