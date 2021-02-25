#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
vector<ll>v;

void prime_factor(ll n)
{
    ll i,j,cnt=0;
    while(n%2==0)
    {
        n/=2;
        cnt++;
    }
    if(cnt>0)v.pb(2);
    for(i=3;i<=sqrt(n);i+=2)
    {
        cnt=0;
        while(n%i==0)
        {
            n/=i;
            cnt++;
        }
        if(cnt>0)v.pb(i);
    }
    if(n>1)
        v.pb(n);
}
int main()
{
    ll n;
    while(1)
    {
        cin>>n;
        if(n==0)return 0;
        prime_factor(n);
        cout<<n<<" : "<<v.size()<<endl;
        v.clear();

    }
}

