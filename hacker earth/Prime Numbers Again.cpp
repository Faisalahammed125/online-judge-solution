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
#define    MAX              10000
#define    INF              INT_MAX
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int t;
string s;
int mark[MAX+5];
ll dp[MAX+5];
vii prime;
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
void sieve()
{
    mark[0]=mark[1]=1;
    for(int i=2;i<=MAX;i++)
    {
        if(!mark[i])
        {
            for(int j=i*i;j<=MAX;j+=i)mark[j]=1;
        }
    }
    mark[4]=mark[27]=mark[3125]=0;
    for(int i=2;i<=10000;i++)if(!mark[i])prime.pb(i);
}
void pre_cal()
{
     int i;
     rep(i,0,MAX)dp[i]=INF;
     rep(i,1,MAX)
     {
         if(!mark[i])
         {
             dp[i]=1;
             continue;
         }
        for(int j=0;j<prime.size();j++)
         {
             if(prime[j]<i)dp[i]=min(dp[i],dp[i-prime[j]]+1);
             else break;
         }
     }
     //rep(i,1,MAX)cout<<dp[i]<<" ";
}
int main()
{
    sieve();
    pre_cal();
    _ios;
    cin>>t;
    w(t)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}



