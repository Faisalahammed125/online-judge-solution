#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define MAX 5000000
int phi[MAX+2];
llu sum[MAX+2];
void sievePHI(){
    ll i,j;
    for( i=2;i<=MAX;i++){
        if( phi[i]==0){
            phi[i] = i-1;
            for( j = i*2; j<=MAX; j+=i){
                if( phi[j] == 0 )phi[j] = j;
                phi[j] /= i ;
                phi[j] *= (i-1) ;
            }
        }
    }
}
void prefix_sum()
{
    for(ll i=2;i<=MAX;i++)
    {
        sum[i]=phi[i];
        sum[i]*=phi[i];
        sum[i]+=sum[i-1];
    }
}
int main()
{
    sievePHI();
    prefix_sum();
    ll t,a,b;
    scanf("%lld",&t);
    for(int j=1;j<=t;j++)
    {
        scanf("%lld %lld",&a,&b);
        printf("Case %d: %llu\n",j,sum[b]-sum[a-1]);
    }
}
