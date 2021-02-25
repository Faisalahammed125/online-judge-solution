#include<bits/stdc++.h>
using namespace std;
#define MAX 20000001
#define ll long long
int prime[MAX];
vector<int>v;
/*void sieve()
{
    prime[0]=prime[1]=1;
    for(ll i=4; i<MAX; i+=2)
        prime[i]=1;
    int sq=sqrt(MAX)+1;
    for(ll i=3; i<sq; i+=2)
    {
        if(prime[i]==0)
        {
                for(ll j=i*i; j<MAX; j+=i)
                    prime[j]=1;
        }
    }
    for(ll i=3; i<MAX; i+=2)
    {
        if(prime[i]==0)
        {
            v.push_back(i);
        }
    }

}*/
int main()
{
    ll t,n,cnt,i,j,ans;
    scanf("%lld",&t);
    for(ll i=1;i<=t;i++)
    {
        ans=1;
        scanf("%lld",&n);
        while(n%2==0)n=n/2;
        for(ll j=3;j<=sqrt(n);j+=2)
        {
            cnt=0;
            while(n%j==0)
            {
                n=n/j;
                cnt++;
            }
            ans*=(cnt+1);
        }
        if(n>2)ans*=2;
        printf("Case %lld:%lld\n",i,ans-1);

    }
}
