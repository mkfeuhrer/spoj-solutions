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
int x[10]={0,-1,-1,-2,-2,2,2,1,1};
int y[10]={0,-2,2,-1,1,-1,1,-2,2};
using namespace std;
int bfs(int a1,int b1,int a2,int b2)
{
    int mov[9][9],visited[9][9],m,n;
    pair<int,int>p1;
    queue< pair<int,int> >q;
    p1.first=a1;
    p1.second=b1;
    q.push(p1);
    memset(mov,0,sizeof mov);
    memset(visited,0,sizeof visited);
    visited[a1][b1]=0;
    while(!q.empty())
    {
        p1=q.front();
        q.pop();
        if(p1.first==a2 && p1.second==b2)
        return mov[a2][b2];
        for(int i=1;i<=8;i++)
        {
            m=p1.first+x[i],n=p1.second+y[i];
            if(m>8 || m<1 || n>8 || n<1)
            continue;
            else
            {
                visited[m][n]=1;
                mov[m][n]=mov[p1.first][p1.second]+1;
                q.push(make_pair(m,n));
            }
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char a1,a2;
    ll b1,b2,t;
    scanf("%lld",&t);
    while(t--)  
    {   
        cin>>a1>>b1>>a2>>b2;
        cout<<bfs(a1-'a'+1,b1,a2-'a'+1,b2)<<endl;
    } 
    return 0;
} 