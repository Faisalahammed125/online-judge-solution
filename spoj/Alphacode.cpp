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
ll dp[50005];
int main()
{
    _ios;
    while(true)
    {
        string s;
        cin>>s;
        if(s[0]=='0')return 0;
        fill(dp);
        ll n=s.size();
        dp[0]=dp[1]=1;
        for(ll i=2;i<=n;i++)
        {
            ll x=s[i-2]-'0';
            ll y=s[i-1]-'0';
            if(x==1||(x==2&&y<=6))dp[i]+=dp[i-2];
            if(y!=0)dp[i]+=dp[i-1];
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}

