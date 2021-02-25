#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main ()
{
    ll t,n,x,arr[100000];
    cin>>t;
    for(ll tt=1;tt<=t;tt++)
    {
        cin>>n;
        ll gcd,lcm;
        cin>>arr[0];
        lcm=arr[0];
        for(ll i=1;i<n;i++)
        {
           cin>>arr[i];
           gcd=__gcd(arr[i],lcm) ;
           lcm=(arr[i]*lcm)/gcd;
        }
        printf("Case %lld: %lld\n",tt,lcm);

    }
}
