#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t,n,m,k,p;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>n;
        cin>>m;
        k=n/(m*2);
        p=m*m;
        cout<<"Case "<< i<<": "<<k*p<<endl;
    }
}
