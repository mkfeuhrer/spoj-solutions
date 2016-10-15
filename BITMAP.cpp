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
char arr[182][182];
int ans[182][182];
int calculate(int x,int y,int n,int m)
{
    if(x<0 || x>=n || y<0 || y>=m)
    return 0;
    if(ans[x][y]!=-1)return ans[x][y];
    if(arr[x][y]=='1') return 0;
    else
    { 
        int a = 1 +  calculate(x+1,y,n,m);
        int b = 1 +  calculate(x-1,y,n,m);
        int c = 1 +  calculate(x,y+1,n,m);
        int d = 1 +  calculate(x,y-1,n,m);
        return ans[x][y] = min(a,min(b,min(c,d)));
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        for(int i = 0;i < 182;i++)
        {
            for(int j = 0;j<182 ;j++)
            {
                ans[i][j]=-1;
            }
        }
        scanf("%d %d",&n,&m);
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j<m ;j++)
            {
                scanf("%c",&arr[i][j]);
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j <m;j++)
            {
                if(ans[i][j]!=-1)
                    printf("%d ",ans[i][j]);
                else calculate(i,j,n,m);
            }
            printf("\n");
        }
    }
    return 0;
}