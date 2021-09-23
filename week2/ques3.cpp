#include<iostream>
using namespace std;
int main()
{
    int T,i,j,k,f;
    cin>>T;
    while(T>0)
    {
        int n;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        int c =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(arr[i]-arr[j])==k){
                c++;
                }
            }
        }
        cout<<c;
        --T;
        cout<<"\n";
    }
    return 0;
}