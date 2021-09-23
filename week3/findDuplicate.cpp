#include<iostream>
using namespace std;
void heapy(int arr[],int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapy(arr, n, largest);
    }

}
int main()
{
    int T,n,i,f=0;
    cin>>T;
    while(T>0)
    {
        cin>>n;         //array size
        int arr[n];
        for(i=0;i<n;i++)        // input n elements
            cin>>arr[i];
        
        //ALGO FOR FINDING DUPLICATES IN ARRAY

        //first we have to sort the array 
        // for sorting purpose we will use heap sort as time complexity will be O(nlogn).

        for (int i = n / 2 - 1; i >= 0; i--)
            heapy(arr, n, i);
        for (int i = n - 1; i > 0; i--) 
        {
            swap(arr[0], arr[i]);
            heapy(arr, i, 0);
        }

        for(i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1])
            {
                f=1;
                break;
            }
        }

        if(f==1)
            cout<<"YES";
        else
            cout<<"NO";

        --T;
        cout<<"\n";
    }
    return 0;
}
