#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
vector<ll>v;

void prime_factor(ll n)
{
    ll i,j;
    while(n%2==0)
    {
        n/=2;
        v.pb(2);
    }
    for(i=3;i<=sqrt(n);i+=2)
    {
        while(n%i==0)
        {
            n/=i;
            v.pb(i);
        }
    }
    if(n>1)
        v.pb(n);
}


int main()
{
    ll x;
    while(1)
    {
        cin>>x;
        if(x==0)return 0;
        prime_factor(abs(x));
        cout<<x<<" =";
        if(x<0)cout<<" -1 x";
        for(int i=0;i<v.size()-1;i++)
        {
            cout<<" "<<v[i]<<" x";
        }
        cout<<" "<<v[v.size()-1]<<endl;
        v.clear();
    }
}
