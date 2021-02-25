#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define llu unsigned long long
vector<llu>v[1000];
void fibonachi()
{
    llu i,j,fib1,fib2,fib3;
    for(i=2;i<=1000;i++)
    {
        v[i].pb(0);
        v[i].pb(1);
        fib1=0,fib2=1;
        for(j=1;j<=3000;j++)
        {
            fib1=fib1%i;
            fib2=fib2%i;
            fib3=fib1+fib2;
            fib3=fib3%i;
            v[i].pb(fib3);
            fib1=fib2;
            fib2=fib3;
            if(fib1==0&&fib2==1)break;
        }
    }

}
llu big_mod(llu a,llu b,llu c)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        llu ret=big_mod(a,b/2,c);
        return((ret%c)*(ret%c))%c;
    }
    else return((a%c)*(big_mod(a,b-1,c)%c)%c);
}
int main()
{
    fibonachi();
    llu n,t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        if(n==1)
        {
            cout<<0<<endl;
        }
        else
        {
            llu c=v[n].size()-2;
        llu ans=big_mod(a,b,c);
        cout<<v[n][ans]<<endl;
        }
    }

}
