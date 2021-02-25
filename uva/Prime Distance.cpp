#include<bits/stdc++.h>
#define ll long long
#define MAX 1000000
using namespace std;
ll prime[MAX+1];
ll mark[MAX+1];
ll nprime=0;
void sieve()
{
    ll sq=sqrt(MAX)+2;
    mark[0]=mark[1]=1;
    prime[nprime++]=2;
    for(ll i=4; i<=MAX; i+=2)
        mark[i]=1;
    for(ll i=3; i<=MAX; i+=2)
    {
        if(mark[i]==0)
        {
            prime[nprime++]=i;
            if(i<=sq)
            {
                for(ll j=i*i; j<=MAX; j+=i*2)
                    mark[j]=1;
            }
        }
    }

}
ll is_prime(ll b)
{
    ll check=0;
    ll sq=sqrt(b);
    for(ll i=0; i<nprime,prime[i]<sq; i++)
    {
        if(b%prime[i]==0)
        {
            check=1;
            break;
        }
    }
    return check;

}
int main()
{
    sieve();
    ll a,b,i,j,mini,maxi,rslt1,rslt2,rslt3,rslt4,arr[1000000];
    while( scanf("%lld %lld",&a,&b)==1)
    {
        ll cnt,m;
        if(a<=MAX&&b<=MAX)
        {
            cnt=0;
            m=0;
            for(i=a; i<=b; i++)
            {
                if(mark[i]==0)
                {
                    arr[m++]=i;
                    cnt++;
                }
            }
            mini=100005;
            maxi=-1;
            for(i=0; i<m-1; i++)
            {
                if(arr[i+1]-arr[i]<mini)
                {
                    mini=arr[i+1]-arr[i];
                    rslt1=arr[i];
                    rslt2=arr[i+1];
                }
                if(arr[i+1]-arr[i]>maxi)
                {
                    maxi=arr[i+1]-arr[i];
                    rslt3=arr[i];
                    rslt4=arr[i+1];
                }
            }
            if(cnt>=2)
                printf("%lld,%lld are closest, %lld,%lld are most distant.\n",rslt1,rslt2,rslt3,rslt4);
            else
                printf("There are no adjacent primes.\n");
        }

        else
        {
            cnt=0;
            m=0;
            for(i=a; i<=b; i++)
            {
                if(is_prime(i)==0)
                {
                    arr[m++]=i;
                    cnt++;
                }
            }
            mini=100005;
            maxi=-1;
            for(i=0; i<m-1; i++)
            {
                if(arr[i+1]-arr[i]<mini)
                {
                    mini=arr[i+1]-arr[i];
                    rslt1=arr[i];
                    rslt2=arr[i+1];
                }
                if(arr[i+1]-arr[i]>maxi)
                {
                    maxi=arr[i+1]-arr[i];
                    rslt3=arr[i];
                    rslt4=arr[i+1];
                }
            }
            if(cnt>=2)
                printf("%lld,%lld are closest, %lld,%lld are most distant.\n",rslt1,rslt2,rslt3,rslt4);
            else
                printf("There are no adjacent primes.\n");
        }
    }

}
