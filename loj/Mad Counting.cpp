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

int main()
{
    _ios;
    ll t,n;
    ll arr[10005];
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>n;
        for(ll j=0;j<n;j++)
        {
            cin>>arr[j];
            arr[j]++;
        }
        sort(arr,arr+n);
        ll ans=0;
        for(ll j=0;j<n;)
        {
           ll x=arr[j];
           ll cnt=0;
           while(x==arr[j]&&j<n)
           {
               cnt++;
               j++;
           }
           if(cnt>x)
           {
               ll y=(cnt+x-1)/x;
               x=x*y;
           }
           ans+=x;
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}

