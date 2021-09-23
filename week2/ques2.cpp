#include<iostream>
using namespace std;
int find(int arr[], int n, int key)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==key)
            return mid;
        else if(key>arr[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int main()
{
    int T,i,j,k,f;
    int I,J,K;
    cin>>T;
    while(T>0)
    {
        int n;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                int sum=arr[i]+arr[j];
                k = find(arr,n,sum);
                if(k>0)
                {
                    f=1;
                    I=i+1;
                    J=j+1;
                    K=k+1;
                }
            }
        }
        if (f==1)
        {
            cout<<I<<","<<J<<","<<K;
        }
        else
            cout<<"NO PATTERN SEEN";
        cout<<"\n";
        --T;
    }
    return 0;
}