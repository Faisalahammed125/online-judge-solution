#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10000005
int prime[MAX];
vector<int>v;
void sieve()
{
    prime[0]=prime[1]=1;
    for(int i=4; i<MAX; i+=2)
        prime[i]=1;
    int sq=sqrt(MAX)+1;
    for(int i=3; i<sq; i+=2)
    {
        if(prime[i]==0)
        {
                for(int j=i*i; j<MAX; j+=i)
                    prime[j]=1;
        }
    }

}
int main()
{
    sieve();
    ll x;

    while(1)
    {
        cin>>x;
        if(x==0)return 0;
        ll flag=0;
        for(ll i=0;i<=x/2;i++)
        {
            if(prime[i]==0 && prime[x-i]==0)
            {
                flag=1;
                printf("%lld = %lld + %lld\n",x,i,x-i);
                break;
            }
        }
        if(flag==0)printf("Goldbach's conjecture is wrong.\n");
    }
}
