#include<bits/stdc++.h>
using namespace std;

#define   minv(v)    *min_element(v.begin(),v.end())
#define   maxv(v)    *max_element(v.begin(),v.end())
#define   unq(v)     sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
#define   tt(x)      scanf("%d",&x);while(x--)
#define   rep(i,a,b) for(i=a;i<=b;i++)
#define   ll         long long
#define   ull        unsigned long long
#define   pb         push_back
#define   fill(arr)  memset(arr,0,sizeof(arr))
#define   gcd(a,b)   __gcd(a,b)
#define   lcm(a,b)  (a*(b/gcd(a,b)))
#define   pi         acos(-1.00)
#define   MAX        100000005
#define   MOD        1000000000007
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<ll>prime;
bitset<MAX>bt;
void sieve()
{
    bt[0]=bt[1]=1;
    for(int i=4; i<=MAX; i+=2)
        bt[i]=1;
    for(int i=3; i*i<=MAX; i+=2)
    {
        if(bt[i]==0)
        {
            for(int j=i*i; j<=MAX; j+=i)
                bt[j]=1;
        }
    }
    prime.pb(2);
    for(ll i=3;i<=MAX;i+=2)
    {
        if(bt[i]==0)prime.pb(i);
    }
}
unsigned __lcm(ll n)
{
    unsigned ans=1;
    for(ll i=0;i<prime.size()&& prime[i]<=n;i++)
    {
        ll p=prime[i];
        while(p*prime[i]<=n)
            p*=prime[i];
        ans*=p;
    }
    return ans;
}


int main()
{
    _ios;
    sieve();
    ull i,t;
    cin>>t;
    rep(i,1,t)
    {
        ll n;
        cin>>n;
        cout<<"Case "<<i<<": "<<__lcm(n)<<endl;
    }
    return 0;
}

