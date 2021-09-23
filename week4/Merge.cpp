#include<iostream>

using namespace std;

int Comparison=0, Inversion=0;

void mergeArr(int arr[], int l, int s, int h)
{
    int n = h - l + 1, temp[n], i = l, j = s + 1, k = 0, noi = 0;
    while (i <= s && j <= h)
    {
        Comparison++;
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            Inversion += s - i + 1;
        }
    }
    for (; i <= s; ++i, ++k)
        temp[k] = arr[i];
    for (; j <= h; ++j, ++k)
        temp[k] = arr[j];

    for (int i = l, j = 0; i <= h; ++i, j++)
        arr[i] = temp[j];
}

void mergeSort(int arr[], int l, int h)
{
    int noc = 0;
    if (l < h)
    {
        int splitInd = (l + h) / 2;
        mergeSort(arr, l, splitInd);
        mergeSort(arr, splitInd + 1, h);
        mergeArr(arr, l, splitInd, h);
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
        Comparison=Inversion=0;
        mergeSort(arr,0,n-1);

        //output format

        for(i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n comparisons ="<<Comparison;
        cout<<"\n inversions ="<<Inversion;
        --T;
        cout<<"\n";
    }
    return 0;
}