#include<iostream>
#include<algorithm>
using namespace std;

void sum(int arr[],int n,int key){
	int left=0;
	int right=n-1;
	int flag=0;
	while(left<right){
		if(arr[left]+arr[right]==key){
			cout << arr[left] << " " << arr[right] << ",";
			right--;
			flag++;
		}
		else if(arr[left]+arr[right]>key){
			right--;
		}
		else if(arr[left]+arr[right]<key){
			left++;
		}
	}
	if(flag==0)
			cout << "No Such Pair Exist\n";
		else
			cout << endl;
}
int main()
{
    int T,n,i,key,j;
    cin>>T;
    while(T>0)
    {
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        cin>>key;
    
        sort(arr,arr+n);
	 	sum(arr,n,key);
        --T;
    }
    return 0;
}