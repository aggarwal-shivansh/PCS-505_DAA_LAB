#include<iostream>
using namespace std;
int main()
{
    int T,n,i,key,j,s,c;
    cin>>T;
    while(T>0)
    {
        cin>>n;         //array size
        int arr[n];
        for(i=0;i<n;i++)        // input n elements
            cin>>arr[i];
        
        //ALGO FOR INSERTION SORT
        c=0,s=0;

        for (i = 1; i < n; i++)
        {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            ++c;
            ++s;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        ++s;
        arr[j + 1] = key;
        }

        //output format

        for(i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n comparison = "<<c;
        cout<<"\n shifts = "<<s;
        --T;
        cout<<"\n";
    }
    return 0;
}