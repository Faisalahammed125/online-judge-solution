#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    if(n==1)cout<<1<<endl;
    else if(n==3)cout<<4<<endl;
    else
    {
        ll x=n/2;
        ll ans=pow(2,x-1);
        ans*=3;
        cout<<ans<<endl;
    }
}
