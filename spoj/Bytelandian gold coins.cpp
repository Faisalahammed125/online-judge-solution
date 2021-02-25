#include<bits/stdc++.h>
using namespace std;

#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define unq(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
#define ll long long
#define pb push_back
#define fill(arr) memset(arr,0,sizeof(arr))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define pi acos(-1.00)
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

map<ll, ll> dp;

ll coin(ll n)
{
    if(n<11)return n;
    if(dp[n]!=0)
        return dp[n];
    dp[n] =max(n,coin(n/2)+coin(n/3)+coin(n/4));
    return dp[n];
}
int main()
{
    _ios;
    ll n;
    while(scanf("%lld",&n)==1)
    {
       cout<<coin(n)<<endl;
    }
    return 0;
}

