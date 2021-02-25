#include<bits/stdc++.h>
using namespace std;

#define MAX 100000005
#define ll long long

bool vis[MAX];
vector<int>prime;

void sieve()
{
    ll i,j;
    vis[0]==vis[1]==1;
    for( i=2; i*i<=MAX; i++)
    {
        if(!vis[i])
        {
            for( j=i+i; j<=MAX; j+=i)
                vis[j]=1;
        }
    }
    prime.push_back(2);
    for(i=3;i<=MAX;i+=2)
    {
        if(!vis[i])prime.push_back(i);
    }
}
int main()
{
    sieve();
    ll t,n;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>n;
        ll ans=0;
        for(ll j=0;prime[j]<=(n/2);j++)
        {
            if(!vis[n-prime[j]])ans++;
        }
        printf("Case %lld: %lld\n",i,ans);
    }
}
