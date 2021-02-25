#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t;
    ll arr[100005];
    cin>>t;
    string s;
    getchar();
    while(t--)
    {
        getline(cin,s);
        stringstream ss(s);
        ll x=0;
        while(ss>>arr[x])
            ++x;
        ll gcd=0;
        for(ll i=0;i<x;i++)
        {
            for(ll j=i+1;j<x;j++)
            {
                gcd=max(gcd,__gcd(arr[i],arr[j]));
            }
        }
        cout<<gcd<<endl;
    }
}
