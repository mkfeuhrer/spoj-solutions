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
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000007
int n,m,cnt=0;
int r[4]={-1,1,0,0};
int c[4]={0,0,1,-1};
int arr[251][251],vis[251][251];
int dfs(int x,int y)
{
	if(x<0 || x>=n || y<0 || y>=m)
	return 0;
	cnt++;
	for(int i=0;i<4;++i)
    {
          int tmpr=x+r[i];
          int tmpc=y+c[i];
          if((tmpr>=0 && tmpr<n) && (tmpc>=0 && tmpc<m) && !vis[tmpr][tmpc])
          {
               if(arr[tmpr][tmpc]== 1)
               {
                    vis[tmpr][tmpc]=1;
                    dfs(tmpr,tmpc);
               }
          }
    }
	return cnt;
}
int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 	while(1)
 	{
 		int maxm = 0,ct=0;
 		scanf("%d %d",&n,&m);
 		if(n==0 || m==0) return 0;
 		vector< pii > v;
 		pii l;
 		for(int i =0 ;i<n;i++)
 		{
 			for(int j = 0;j<m;j++)
 			{
 				scanf("%d",&arr[i][j]);
 				if(arr[i][j]==1)
 				{
 					l=mp(i,j);
 					v.push_back(l);
 					//cout<< i << " "<<j<<endl;
 				}
 			}
 		}
 		int ans[62505];
 		memset(ans,0,sizeof(ans));
 		for(int i = 0;i<v.size();i++)
 		{
 			if(vis[v[i].first][v[i].second]!=1)
 			{
 				ct++;
 				cnt=0;
 				vis[v[i].first][v[i].second]=1;
 				int a = dfs(v[i].first,v[i].second);
 				ans[a]++;
 				maxm = max(maxm , a);
 				//cout<<a<<" "<<maxm<< endl;
 			}
 		}
 		ct=ct-ans[0];
 		ans[0]=0;
 		//cout<<ans[20]<<endl;
 		printf("%d\n",ct);
 		for(int i = 0;i<=maxm;i++)
 		{
 			if(ans[i]!=0)
 			{
 				printf("%d %d\n",i,ans[i]);
 			}
 		}
 		for(int i =0;i<= 251;i++)
 		{
 			for (int j = 0; j <= 251; ++j)
 			{
 				arr[i][j]=0;
 				vis[i][j]=0;
 			}
 		}
 	}
	return 0;
}