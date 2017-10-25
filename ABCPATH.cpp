/* Name: Mohit Khare
B.Tech 2nd Year
Computer Science and Engineering
MNNIT Allahabad
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define VI vector<int>
#define VS vector<string>
typedef pair<int,int> pii;
#define ALL(x) x.begin(), x.end()
int vis[50][50];
char ch[50][50];
int coun=0;
int n,m;

void dfs(int row,int col, int depth)
{
     if(depth > coun)
        coun = depth;

     int r[8]={-1,-1,-1,0,0,1,1,1};
     int c[8]={-1,0,1,-1,1,-1,0,1};

     for(int i=0;i<8;++i)
     {
          int tmpr=row+r[i];
          int tmpc=col+c[i];
          if((tmpr>=0 && tmpr<n) && (tmpc>=0 && tmpc<m) && !vis[tmpr][tmpc])
          {
               if(ch[tmpr][tmpc]== ch[row][col] + 1)
               {
                    vis[tmpr][tmpc]=1;
                    dfs(tmpr,tmpc,depth+1);
               }
          }
     }
}

int main()
{
     scanf("%d%d",&n,&m);
     int t=0, u ;
     while(n!=0 && m!=0)
     {
          coun=0;
          t++;
          for(int i=0;i<n;++i)
               for(int j=0;j<m;++j)
               {
                    cin>>ch[i][j];
                    vis[i][j]=0;
               }
          for(int i=0;i<n;++i)
               for(int j=0;j<m;++j)
               {
                    if(ch[i][j]=='A')
                    {
                         vis[i][j]=1;
                         dfs(i,j,1);
                    }
               }
          printf("Case %d: %d\n",t,coun);
          scanf("%d%d",&n,&m);
     }
     return 0;
}
