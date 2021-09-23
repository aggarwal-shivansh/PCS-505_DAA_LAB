#include<iostream>
#include<algorithm>
using namespace std;
char c[26];
void count (char arr[], int n)
{
    for(int i=0;i<26;i++)
		c[i]=0;
	for(int i=0;i<n;i++){
		++c[(int)(arr[i])-97];
	}
}
int main()
{
    int T,n,i,j;
    cin>>T;
    while(T>0)
    {
        cin>>n;
        char arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];

        count(arr,n);
		int m= *max_element(c,c+26);
		int index = max_element(c,c+26)-c;
		char alph = 'a' + (char)(index);
		if(m>1)
			cout << alph << "-" << m << endl;
		else
			cout << "No Duplicate Present" << endl;
        --T;
    }
    return 0;
}