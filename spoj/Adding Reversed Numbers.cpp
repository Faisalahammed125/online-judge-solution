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
unsigned rev(unsigned n)
{
    unsigned p=0;
    while(n)
    {
        p=p*10+n%10;
        n/=10;
    }
    return p;
}
int main()
{
    _ios;
    ll t;
    cin>>t;
    while(t--)
    {
        unsigned x,y;
        cin>>x>>y;
        cout<<rev(rev(x)+rev(y))<<endl;
    }
    return 0;
}

