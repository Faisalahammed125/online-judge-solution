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
        if(prime[i]==0&&prime[i+2]==0)
        {
            v.push_back(i);
        }
    }

}
int main()
{
    sieve();
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("(%d, %d)\n",v[n-1],v[n-1]+2);
    }
}
