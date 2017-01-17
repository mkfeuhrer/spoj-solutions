/* Name: Mohit Khare
B.Tech 2nd Year
Computer Science and Engineering
MNNIT Allahabad
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define ALL(x) x.begin(), x.end()
#define boost ios_base::sync_with_stdio(false);

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(i=a;i<b;i++)
#define REN(i,a,b) for(i=a;i>b;i--)

//const int dx[4]={0,1,0,-1};
//const int dy[4]={1,0,-1,0};

#define mod 1000000007
const int maxn=1e5+1;
int n;
int arr[1000];
void update(int x,int v)
{
	for(;x<=n;x+=x&(-x))
	arr[x]+=v;
}
void upd(int l,int u,int v)
{
	update(l,v);
	update(u+1,-v);
}
int query(int x)
{
	int sum=0;
	for(;x>0;x-=x&(-x))
		sum+=arr[x];
        return sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
	int u;
	cin>>n>>u;
	memset(arr,0,sizeof(arr));
	for(int i = 0; i<u;i++)
	{
		int l,u,v;
		cin>>l>>u>>v;
		upd(l,u,v);
	}
	int q;
	cin>>q;
	for(int i = 0; i<q;i++)
	{
		int s;
		cin>>s;
		cout<<query(s)<<endl;
	}
    }
}
