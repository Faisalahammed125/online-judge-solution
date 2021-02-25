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
    ll t,n;
    cin>>t;
    for(ll tt=1;tt<=t;tt++)
    {
        cin>>n;
        ll n1=2*n-1;
        ll arr[205][205];
        ll dp[205][205];
        for(ll i=0;i<n+10;i++)
        {
            for(ll j=0;j<n+10;j++)dp[i][j]=0;
        }
        bool flag=true;
        ll k=0;
        for(ll i=0;i<n1;i++)
        {
            if(k==n)flag=false;
            if(flag)k++;
            else k--;
            for(ll j=0;j<k;j++)cin>>arr[i][j];
        }
        dp[0][1]=arr[0][0];
        flag=true;
         k=1;
        for(ll i=1;i<n1;i++)
        {
            if(k==n)flag=false;
            if(flag)k++;
            else k--;
            for(ll j=1;j<=k;j++)
            {
                if(flag)dp[i][j]=arr[i][j-1]+max(dp[i-1][j],dp[i-1][j-1]);
                else dp[i][j]=arr[i][j-1]+max(dp[i-1][j],dp[i-1][j+1]);
            }
        }
        cout<<"Case "<<tt<<": "<<dp[n1-1][1]<<endl;

    }
    return 0;
}


