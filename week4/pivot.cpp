#include<iostream>
using namespace std;
int comp,swaps;

void swap(int *p, int *t)
{
    ++swaps;
    int tmp=*p;
    *p=*t;
    *t=tmp;
}

int part_it(int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) 
    { 
        ++comp;
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 

        int pi = part_it(arr, low, high); 
        quickSort(arr, low, pi - 1);  //sort elements before partition
        quickSort(arr, pi + 1, high); //sort elements after partition.
    } 
} 

int main()
{
    int T,n,i;
    cin>>T;
    while(T>0)
    {
        cin>>n;     //n input
        int arr[n];
        for(i=0;i<n;i++)    //input n elements
            cin>>arr[i];
        comp=swaps=0;
        quickSort(arr,0,n-1);

        //output format

        for(i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n comparisons ="<<comp;
        cout<<"\n swaps ="<<swaps;
        --T;
        cout<<"\n";
    }
    return 0;
}