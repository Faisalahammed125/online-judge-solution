#include<bits/stdc++.h>
using namespace std;
#define MAX 20000001
#define ll long long
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
    for(int i=0; i<MAX; i++)
    {
        if(prime[i]==0)
        {
            v.push_back(i);
        }
    }

}

int main()
{
    sieve();
    ll t=1,n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)return 0;
        if(n==1)
        {
             printf("Case %lld: %lld\n",t,n+1);
             t++;
             continue;
        }
        ll sq=sqrt(n)+1;
        ll p=0,nn=n,sum=0,flag=0;
        while(p<v.size()&&nn!=1)
        {
            if(nn%v[p]==0)
            {
                ll temp=1;
                while(nn%v[p]==0)
                {
                    temp=temp*v[p];
                    nn=nn/v[p];
                }
                sum=sum+temp;
                flag++;
            }
            p++;
            if(v[p]>sq)break;

        }
        if(nn!=1)
        {
            sum=sum+nn;
            flag++;
        }
        if(flag==1)sum=1+n;
        printf("Case %lld: %lld\n",t,sum);
        t++;
    }
}
