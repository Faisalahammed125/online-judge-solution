#include<bits/stdc++.h>
using namespace std;

#define   minv(v)    *min_element(v.begin(),v.end())
#define   maxv(v)    *max_element(v.begin(),v.end())
#define   unq(v)     sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
#define   tt(x)      scanf("%d",&x);while(x--)
#define   rep(i,a,b) for(i=a;i<=b;i++)
#define   ll         long long
#define   pb         push_back
#define   fill(arr)  memset(arr,0,sizeof(arr))
#define   gcd(a,b)   __gcd(a,b)
#define   lcm(a,b)  (a*(b/gcd(a,b)))
#define   pi         acos(-1.00)
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll arr[500005];
int main()
{
    _ios;
    while(1)
    {
        ll n;
        cin>>n;
        vector<ll>v1;
        vector<ll>v2;
        if(n==0)return 0;
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>=0)v2.pb(i);
            else v1.pb(i);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        ll j=0,ans=0;
        for(ll i=0;i<v1.size();)
        {
           ll idx1=v1[i];
           ll idx2=v2[j];
           ll s=arr[idx1]+arr[idx2];
           if(s==0)
           {
              ll temp=abs(idx1-idx2)*abs(arr[idx1]);
              ans+=temp;
              j++;
              i++;
           }
           else if(s>0)
           {
               ll temp=abs(idx1-idx2)*abs(arr[idx1]);
               ans+=temp;
               arr[idx2]=s;
               i++;
           }
           else
           {
               ll temp=abs(idx1-idx2)*abs(arr[idx2]);
               ans+=temp;
               arr[idx1]=s;
               j++;
           }
        }
        cout<<ans<<endl;
    }
    return 0;
}

