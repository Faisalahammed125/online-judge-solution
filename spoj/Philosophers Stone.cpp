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
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    _ios;
    ll t,h,w;
    cin>>t;
    while(t--)
    {
        cin>>h>>w;
        ll arr[200][200];
        ll dp[200][200];
        for(ll i=0;i<h+10;i++)
        {
            for(ll j=0;j<w+10;j++)dp[i][j]=0;
        }
        for(ll i=0;i<h;i++)
        {
            for(ll j=0;j<w;j++)cin>>arr[i][j];
        }
        for(ll i=0;i<1;i++)
        {
            for(ll j=0;j<w;j++)dp[i][j+1]=arr[i][j];
        }
        for(ll i=1;i<h;i++)
        {
            for(ll j=1;j<=w;j++)
            {
                dp[i][j]=arr[i][j-1]+max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
            }
        }
        ll mx=-1;
        for(ll i=1;i<=w;i++)
        {
           mx=max(mx,dp[h-1][i]) ;
        }
        cout<<mx<<endl;

    }
    return 0;
}

