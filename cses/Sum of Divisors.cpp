#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
#define  pi      acos(-1)
#define  mod     1000000007
using namespace std;

int power(int a,int n){
    int res=1;
    while(n){
        if(n%2)res=(res*a)%mod;
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}
int inv=power(2,mod-2);

int sum(int n){
    return ((((n%mod)*((n+1)%mod))%mod)*inv)%mod;
}

int divisor_sum(int n){
    int l=1,k,r;
    int ans=0;
    while(l<=n){
        k=n/l;
        r=n/k;
        ans+=((sum(r)-sum(l-1))*k)%mod;
        ans=ans%mod;
        l=r+1;
    }
    ans=ans%mod;
    if(ans<0){
        ans+=mod;
    }
    return ans;
}

signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   int n;
   cin>>n;
   cout<<divisor_sum(n)<<endl;
   return 0;
}
