/*SHIVANSH AGGARWAL 2014860*/
/*SECTION - A */
/*CLASS ROLL NO - 52*/
/*WEEK 0*/

#include<iostream>
using namespace std;

int main()
{
    int T,n,i,f=0,key,comparisons;
    cin>>T;
    while(T>0)
    {
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        cin>>key;
        f=comparisons=0;
        //linear search 

        for(i=0;i<n;i++)
        {
            ++comparisons;
            if(key==arr[i])
            {
                f=1;
                break;
            }
        }
        if(f==1)
            cout<<"FOUND \n COMPARISONS ="<<comparisons;
        else
            cout<<"NOT FOUND";

        --T;
        cout<<"\n";
    }
    return 0;
}