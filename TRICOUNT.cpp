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
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    t=100;
    while(t--)
    {
        long long unsigned num=t,sum;
        if(num%2==0)
        sum=(num*(num+2)*((2*num)+1))/8;
        else
        sum=((num*(num+2)*((2*num)+1))-1)/8;
        printf("%llu\n",sum);
    }
    return 0;
}

    
