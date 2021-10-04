#include<bits/stdc++.h>
#define  MX      1000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
#define  pi      acos(-1)
#define  mod     1000000007
using namespace std;

int fact[MX];

int power(int a,int n){
    int res=1;
    while(n){
        if(n%2)res=(res*a)%mod;
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}

void factorial(){
    fact[0]=fact[1]=1;
    for(int i=2;i<MX;i++)fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
}

int C(int n,int r){
    int res=fact[n];
    res=(res*power(fact[r],mod-2))%mod;
    res=(res*power(fact[n-r],mod-2))%mod;
    return res;
}

signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   factorial();
   int a,b,n,k;
   cin>>a>>b>>n>>k;
   int res=(C(n,k)*power(a,k))%mod;
   res=(res*power(b,n-k))%mod;
   cout<<res<<endl;
   return 0;
}
