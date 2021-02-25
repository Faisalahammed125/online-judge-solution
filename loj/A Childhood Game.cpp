#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string a="Alice";
    string b="Bob";
    ll t,n;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        cin>>n;
        string s;
        cin>>s;
        n=n%3;
        if(s==a)
        {
            if(n==0 or n==2)cout<<"Case "<<i<<": "<<a<<endl;
            else cout<<"Case "<<i<<": "<<b<<endl;
        }
        else
        {
            if(n==1 or n==2)cout<<"Case "<<i<<": "<<b<<endl;
            else cout<<"Case "<<i<<": "<<a<<endl;
        }
    }
}
