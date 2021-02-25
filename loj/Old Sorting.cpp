#include<bits/stdc++.h>
using namespace std;

#define   minv(v)    *min_element(v.begin(),v.end())
#define   maxv(v)    *max_element(v.begin(),v.end())
#define   unq(v)     sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
#define   tt(x)      scanf("%d",&x);while(x--)
#define   rep(i,a,b) for(i=a;i<=b;i++)
#define   repi(i,n) for(i=1;i<=n;i++)
#define   ll         long long
#define   pb         push_back
#define   fill(arr)  memset(arr,false,sizeof(arr))
#define   gcd(a,b)   __gcd(a,b)
#define   lcm(a,b)  (a*(b/gcd(a,b)))
#define   pi         acos(-1.00)
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll arr[1005];
bool vis[1005];
int main()
{
    _ios;
    ll t,i,n;
    cin>>t;
    rep(i,1,t)
    {
        cin>>n;
        fill(vis);
        ll j;
        repi(j,n)
        {
            cin>>arr[j];
        }
        ll s=0;
        repi(j,n)
        {
            if(!vis[j])vis[j]=true;
            if(arr[j]!=j)
            {
                ll c=arr[j];
                while(!vis[c])
                {
                    vis[c]=true;
                    c=arr[c];
                    s++;
                }
            }
        }
        cout<<"Case "<<i<<": "<<s<<endl;
    }
    return 0;
}

