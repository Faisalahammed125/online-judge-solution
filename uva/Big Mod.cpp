#include<bits/stdc++.h>
using namespace std;
long long m;
long long big_mod(long long b,long long p)
{
    if(p==0)return 1;
    if(p%2==0)
    {
        long long ret=big_mod(b,p/2);
        return ((ret%m)*(ret%m))%m;
    }
    else return ((b%m)*(big_mod(b,p-1))%m)%m;
}
int main()
{
    long long b,p;
    while(cin>>b>>p>>m)
    cout<<big_mod(b,p)<<endl;
}
