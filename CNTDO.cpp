#include<bits/stdc++.h>
using namespace std;
int main()
{
	int hash[10005],hash2[10005];
	int t;
	cin>>t;
	while(t--)
	{
	int n,count=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<10005;i++)
	{
		hash[i]=0;
		hash2[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]>=0)
		hash[arr[i]]=1;
		else
			hash2[abs(arr[i])]=1;
	}
	for(int i=0;i<n;i++)
	{
			if(abs(arr[i])<5001)
				if(arr[i]>=0)
				{
					if(hash[arr[i]*2]==1)
					count++;
				}
				else
				{
					if(hash2[abs(arr[i])*2]==1)
					count++;
				}
	}
	cout<<count<<endl;
	}
	return 0;
}