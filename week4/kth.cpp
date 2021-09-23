#include<iostream>
#include<climits>
using namespace std;

void swap(int* p, int* t)
{
    int temp = *p;
    *p = *t;
    *t = temp;
}
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) {
        int pos = partition(arr, l, r);
 
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1) 
            return kthSmallest(arr, l, pos - 1, k);
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
 
    // If k is more than number of elements in array
    return INT_MAX;
}
int main()
{
    int T,n,i,k;
    cin>>T;
    while(T>0)
    {
        cin>>n;     //n input
        int arr[n];
        for(i=0;i<n;i++)    //input n elements
            cin>>arr[i];
        cin>>k;  // kth element
        cout<<kthSmallest(arr,0,n-1,k);
        cout<<"\n";
        --T;
    }
    return 0;
}

