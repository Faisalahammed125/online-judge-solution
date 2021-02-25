#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,n,i;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n;
        ll sq=ceil(sqrt(n));
        ll r,c;
        ll x=sq*sq-n;
        if(x+1<=sq)
        {
            r=sq;
            c=x+1;
        }
        else
        {
            c=sq;
            x-=sq-1;
            r=sq-x;
        }
        if(sq%2==0)
            swap(r,c);
        printf("Case %lld: %lld %lld\n", i, c, r);
    }
}
