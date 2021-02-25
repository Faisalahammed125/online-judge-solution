#include<bits/stdc++.h>
using namespace std;

#define   minv(v)    *min_element(v.begin(),v.end())
#define   maxv(v)    *max_element(v.begin(),v.end())
#define   unq(v)     sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
#define   tt(x)      scanf("%lld",&x);while(x--)
#define   rep(i,a,b) for(i=a;i<=b;i++)
#define   repi(i,n) for(i=0;i<n;i++)
#define   ll         long long
#define   pb         push_back
#define   fill(arr)  memset(arr,false,sizeof(arr))
#define   gcd(a,b)   __gcd(a,b)
#define   lcm(a,b)  (a*(b/gcd(a,b)))
#define   pi         acos(-1.00)
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll arr[100005];
bool vis[1000005];
int main()
{
    _ios;
    ll t;
    cin>>t;
    while(t--)
    {
        fill(vis);
       ll n,m,x;
       cin>>n;
       for(ll i=0;i<n;i++)cin>>arr[i];
       cin>>m;
       for(ll i=0;i<m;i++)
       {
           cin>>x;
           vis[x]=true;
       }
       bool flag=false;
       ll cnt=0;
       for(ll i=0;i<n;i++)
       {
           if(vis[arr[i]])flag=true;
           if(!vis[arr[i]]&&flag)
           {
               flag=false;
               cnt++;
           }
       }
       if(flag)cnt++;
       cout<<cnt<<endl;
    }
    return 0;
}

