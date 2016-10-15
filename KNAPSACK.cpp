#include<bits/stdc++.h>
using namespace std;
int knapSack(int s, int wt[], int val[], int n)
{
   int i, w;
   int knap[n+1][s+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= s; w++)
       {
           if (i==0 || w==0)
               knap[i][w] = 0;
           else if (wt[i-1] <= w)
                 knap[i][w] = max(val[i-1] + knap[i-1][w-wt[i-1]], knap[i-1][w]);
           else
                 knap[i][w] = knap[i-1][w];
       }
   }
 
   return knap[n][s];
}
 
int main()
{
    int s,n;
    scanf("%d %d",&s,&n);
    int val[n],wt[n];
    for(int i=0;i<n;i++)
    scanf("%d %d",&wt[i],&val[i]);
    printf("%d", knapSack(s, wt, val, n));
    return 0;
}