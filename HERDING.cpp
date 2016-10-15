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
#define mod 1000000009
char opposite[200];
bool valid(int x , int y , int n , int m)
{
    if(x >=0 && y>=0 && y< m && x<n)
        return true;
    return false;
}
int main()
{
    int n , m;
    scanf("%d%d",&n , &m);
    char arr[n+9][m+9];
    for(int i = 0 ; i < n ; i++)
        scanf("%s",arr[i]);
    int count = 0 , check[n+9][m+9];
    memset(check , 0 , sizeof check);
    int p = 0 , c=0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            queue<pii >q;
            q.push(mp(i , j));
            vector<pii > v;
            v.pb(mp(i , j));
            if(!check[i][j])
            {
                c = p + 1;
                check[i][j] = c;
                while(!q.empty())
                {
                    pii pos = q.front();
                    q.pop();
                    int x = pos.first , y = pos.second;
                    if(arr[x][y] == 'S')
                        x++;
                    else if(arr[x][y] == 'E')
                        y++;
                    else if(arr[x][y] == 'N')
                        x--;
                    else if(arr[x][y] == 'W')
                        y--;
                    if(valid(x , y , n , m) && check[x][y] == 0)
                    {
                        v.pb(mp(x , y));
                        q.push(mp(x , y));
                        check[x][y] = c;
                    } else if(valid(x , y , n , m) && check[x][y]!=0)
                    {
                        int save = check[x][y];
                        if(check[x][y] < c){
                            for(int p = 0 ; p < v.size() ; p++)
                                check[v[p].first][v[p].second] = check[x][y];
                        }
                        c =save;
                        break;
                    }
                }
                if(c>p)
                    p++;
            }
        }
    }
    cout<<p<<endl;
    return 0;
}
