#include <bits/stdc++.h>
using namespace std;
int check[10000002];
int arr[10000][2];
void sieve()
{
    for(int i=2;i<=10000001;i++)
    {
        if(!check[i])
        {
            check[i]=i;
            for(int j=i*2;j<=10000001;j+=i)
                check[j]=i;
        }
    }
}
int nways(int factorlen)
{
    int res = 1, i;
	for(i=0; i<factorlen; i++)
		res *= (arr[i][1]+1);
	return ((res+1) >> 1);
}
int main()
{
        int n;
        sieve();
        while(1)
        {
            for(int i=0;i<10000;i++)
            {
                arr[i][0]=0;
                arr[i][1]=0;
            }
            scanf("%d",&n);
            int k=0,m=n,f=0,l=0;
            if(n==0) break;
            printf("%d = ",m);
            int q=0;
           	while(n > 1)
           	{
           		arr[q][0] = check[n]; // d[n] is the largest prime divisor of n
                int x = check[n];
                while(n % x == 0)
                {
                n /= x;
                arr[q][1]++;// counts the count[d[n]]
                }
                q++;
            }
             for(int  i = q-1; i>=0 ;i--)
            {
                 if(i!=0)
                 {
                 for(int j=0;j<arr[i][1];j++)
                 printf("%d * ",arr[i][0]);
                 }
				 else
                 {
                	 for(int j=0;j<arr[i][1];j++)
                 	 {
                 	  if((j+1)==arr[i][1])
                 	  printf("%d\n",arr[i][0]);
					  else
					  printf("%d * ",arr[i][0]);
					}
             	 }
            }
             long long int ans = nways(q);
            printf("With %d marbles, %lld different rectangles can be constructed.\n",m,ans);
        }
        return 0;
  }
