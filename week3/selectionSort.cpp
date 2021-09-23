#include<iostream>
using namespace std;
void swap(int *p, int *t)
{
    int tmp = *p;
    *p = *t;
    *t = tmp;
}
int main()
{
    int T,n,i,min,j,s,c;
    cin>>T;
    while(T>0)
    {
        cin>>n;         //array size
        int arr[n];
        for(i=0;i<n;i++)        // input n elements
            cin>>arr[i];
        
        //ALGO FOR SELECTION SORT
        c=0,s=0;

        for (i = 0; i < n-1; i++)
        {
        // Find the minimum element in unsorted array
        min = i;
        for (j = i+1; j < n; j++)
        {
            ++c;
            if (arr[j] < arr[min])
                min = j;
        }
        ++s;
        // Swap the found minimum element with the first element
        swap(&arr[min], &arr[i]);
        }
        
        //output format

        for(i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n comparison = "<<c;        //no of comparisons
        cout<<"\n shifts = "<<s;            //no of shifts 
        --T;
        cout<<"\n";
    }
    return 0;
}