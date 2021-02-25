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

int main()
{
    _ios;
    ll n,sx,sy,x1,x2,y1,y2,r1=0,r2=0,r3=0,r4=0;
    cin>>n>>sx>>sy;
    x1=sx+1;
    x2=sx-1;
    y1=sy+1;
    y2=sy-1;
    ll a,b;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(a>=x1)r1++;
        if(a<=x2)r2++;
        if(b>=y1)r3++;
        if(b<=y2)r4++;
    }
    ll mx=max(r1,max(r2,max(r3,r4)));
    if(mx==r1)
    {
        cout<<mx<<endl;
        cout<<x1<<" "<<sy<<endl;
    }
    else if(mx==r2)
    {
        cout<<mx<<endl;
        cout<<x2<<" "<<sy<<endl;
    }
    else if(mx==r3)
    {
        cout<<mx<<endl;
        cout<<sx<<" "<<y1<<endl;
    }
    else if(mx==r4)
    {
        cout<<mx<<endl;
        cout<<sx<<" "<<y2<<endl;
    }
    return 0;
}

