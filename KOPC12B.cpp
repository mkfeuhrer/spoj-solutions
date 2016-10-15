#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll fact[2000020], ifact[2000020];
struct mypair
{
    ll x,y;
    mypair(ll a, ll b)
    {
        x=a, y=b;
    }
};
mypair f(ll a, ll m){
    if(m==0)
        return mypair(1, 0);
    mypair p=f(m, a%m);//gcd concept
    return mypair(p.y, (p.x-(p.y*(a/m))));//extended euclid
}
ll modInv(ll a)
{
    mypair p=f(a,MOD);
    if(p.x<0)
        return p.x+MOD;
    return p.x;
}

ll nCr(ll n, ll r)
{
	return (((fact[n]*ifact[r]) % MOD) * ifact[n-r]) % MOD;
}

int main()
{
	fact[0] = 1;
	ifact[0] = modInv(1);
	for(ll i = 1; i < 2000020; i++)//normal factorial
		fact[i] = (i * fact[i-1]) % MOD;
	for (ll i = 1; i < 1000010; i++)//inverse factorials
		ifact[i] = (ifact[i-1] * modInv(i)) % MOD;
	ll t, n;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld", &n);
		ll ans = (n * nCr(2*n-1, n-1)) % MOD;
		printf("%lld\n", ans);
	}
}
