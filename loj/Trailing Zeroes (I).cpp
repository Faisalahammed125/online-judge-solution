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

const int N=1e5+5;
vector<bool>isprime(N,true);
vector<int>prime;

void sieve()
{
    for(int i=2;i*i<=N;i++)
    {
        if(isprime[i])
        {
            for(int j=i*2;j<=N;j+=i)isprime[j]=false;
        }
    }
    prime.pb(2);
    for(int i=3;i<=N;i+=2)if(isprime[i])prime.pb(i);
}

ll count_div(ll n)
{
    ll div=1,cnt=0;
    for(ll i=0;prime[i]*prime[i]<=n&&i<prime.size();i++)
    {
        cnt=0;
        int x=prime[i];
        while(n%x==0)
        {
            n/=x;
            cnt++;
        }
        div*=(cnt+1);
    }
    if(n>1)div*=2;

    return div-1;
}

int main()
{
    _ios;
    ll t,n;
    sieve();
    //for(int p : prime)cout<<p<<" ";
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>n;
        cout<<"Case "<<i<<": "<<count_div(n)<<endl;
    }
    return 0;
}

