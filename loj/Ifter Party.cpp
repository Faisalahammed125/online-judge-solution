#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v;
int divisors(ll n)
{
    ll sq=sqrt(n)+1;
    for(ll i=1;i<=sq;i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            v.push_back(n/i);
        }
    }
}
int main()
{
    ll t,l,p;
    scanf("%lld",&t);
    for(ll i=1;i<=t;i++)
    {
        scanf("%lld %lld",&p,&l);
        if(p==0||p-l<=l)printf("Case %lld: impossible\n",i);
        else
        {
            divisors(p-l);
            sort(v.begin(),v.end());
            v.resize(distance( v.begin(), unique(v.begin(),v.end())) );
            printf("Case %lld:",i);
            for(ll j=0;j<v.size();j++)
            {
                if(v[j]>l)printf(" %lld",v[j]);
            }
            printf("\n");
        }
        v.clear();
    }
}
