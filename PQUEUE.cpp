/* 
Name : Mohit Khare 
B.Tech 2nd Year
Computer Science and Engineering
MNNIT Allahabad
*/    
#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i > (int)(b); i--)
#define ll long long int
#define ull unsigned long long int
#define pii pair< int, int >
#define pb push_back
#define mp make_pair
#define mod 1000000007
int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll t, n, myjob, pr, i, time=0;
	scanf("%lld",&t);
	while(t--)
	{
		queue< pii > q;
		priority_queue< int > pq;
		scanf("%lld %lld",&n,&myjob);
		for(i=0; i<n; i++)
		{
			scanf("%lld",&pr);
			pq.push(pr);
			q.push(pii(i,pr));
		}
		time = 0;
		while(!q.empty())
		{
			i = q.front().first;
			pr = q.front().second;
			q.pop();
			if(pr != pq.top()) q.push(pii(i,pr));
			else
			{
				time++;
				pq.pop();
				if(i==myjob) break;
			}
		}
		printf("%lld\n",time);
	}
	return 0;
}
