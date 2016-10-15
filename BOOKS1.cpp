#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000009
bool check(int A , vector<int> &v , ull mid){
    int  n = v.size() , i = 0 , t = 1;
    ull count = 0;
    while(i < n)
    {
        if((long long)v[i] > mid)
            return false;
        if(count + (long long )v[i] > mid)
        {
            t++;
            count = 0;
        }
        if(count <= mid)
        {
            count += (long long)v[i];
            i++;
        }
    }
    if(t <= A)
        return true;
    return false;
}
bool print(int pos , int k ,vector<int> &v , ull mid)
{
    ull count = 0;
    int pos_t = -1;
    for(int i = pos ; i>= 0 ; i--){
        if(count + v[i] > mid || i == k-2){
            print(i , k-1  , v , mid);
            pos_t = i;
            break;
        }
        count += v[i];
    }
    if(pos_t >= 0)
        printf("/ ");
    for(int i = pos_t +1 ; i<= pos ; i++)
        printf("%d ", v[i]);
}
ull search(vector<int> &v , int A)
{
    ull low = 1 , high = LLONG_MAX , mid , ans = LLONG_MAX;
    while(low < high)
    {
        mid = (high + low)>>1;
        if(check(A , v , mid))
        {
            ans = min(ans , mid);
            high = mid;
        } else
            low = mid+1;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n , k;
        scanf("%d%d",&n,&k);
        vector<int> v(n);
        for(int i = 0 ; i < n ; i ++){
            scanf("%d",&v[i]);
        }
        v.push_back(0);
        ull ans = search( v , k );
        print(v.size() - 2 , k , v , ans );
        printf("\n");
    }
    return 0;
}