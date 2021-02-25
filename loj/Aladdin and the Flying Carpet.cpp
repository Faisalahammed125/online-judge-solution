#include<bits/stdc++.h>
using namespace std;
#define    bit(a)          __builtin_popcount(a)
#define    all(x)           x.begin(), x.end()
#define    minv(v)         *min_element(all(v))
#define    maxv(v)         *max_element(all(v))
#define    unq(v)           sort(all(v)),v.erase(unique(all(v)),v.end())
#define    w(x)             while(x--)
#define    rep(i,a,b)       for(i=a;i<=b;i++)
#define    ll               long long
#define    pb               push_back
#define    vii              vector<int>
#define    vll              vector<ll>
#define    vcc              vector<char>
#define    sii              set<int>
#define    sll              set<ll>
#define    scc              set<char>
#define    li               list<int>
#define    pii              pair<int,int>
#define    pll              pair<ll,ll>
#define    mii              map<int,int>
#define    mll              map<ll,ll>
#define    fill(arr,x)      memset(arr,x,sizeof(arr))
#define    gcd(a,b)         __gcd(a,b)
#define    lcm(a,b)        (a*(b/gcd(a,b)))
#define    srtc(a,b)        sort(a,a+b,greater<int>())
#define    pi               acos(-1.00)
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*
//find the position of 0 or 1 in binary representation
int zero(int n)
{
    int i=1,pos=0;
    while(n)
    {
        if(n%2==0)pos=i;
        n/=2;
        i++;
    }
    return pos;
}
*/
//--------------Graph Moves--------------------------------------
const int dx[] = {+1,-1,+0,+0};
const int dy[] = {+0,+0,+1,-1};
//const int dx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
//const int dy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
//const int dx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
//const int dy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
//---------------------------------------------------------------

const int N=1000005;
vector<bool>isprime(N+2,true);
vll prime;
int t;
string s;

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
int main()
{
    _ios;
    sieve();
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        ll n,m;
        cin>>n>>m;
        if(m*m>n)
        {
            cout<<"Case "<<tt<<": "<<0<<endl;
            continue;
        }
        ll x=n;
        int div=1;
        for(int i=0;i<prime.size()&&prime[i]*prime[i]<=x;i++)
        {
            int c=0;
            ll p=prime[i];
            if(x%p==0)
            {
                while(x%p==0)
                {
                    x/=p;
                    c++;
                }
                div*=(c+1);
            }
        }
        if(x!=1)div*=2;
        div/=2;
        int cnt=0;
        for(int i=1;i<m;i++)if(n%i==0)cnt++;
        cout<<"Case "<<tt<<": "<<div-cnt<<endl;
    }
    return 0;
}



