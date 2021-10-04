#include<bits/stdc++.h>
#define  MX      1000005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
#define  pi      acos(-1)
#define  p       1000000007
using namespace std;

int fact[MX];

int power(int a,int n){
    int res=1;
    while(n){
        if(n%2)res=(res*a)%p;
        n/=2;
        a=(a*a)%p;
    }
    return res;
}

void factorial(){
    fact[0]=fact[1]=1;
    for(int i=2;i<MX;i++)fact[i]=((fact[i-1]%p)*(i%p))%p;
}

int C(int n,int r){
    int res=fact[n];
    res=(res*power(fact[r],p-2))%p;
    res=(res*power(fact[n-r],p-2))%p;
    return res;
}
signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   int t;
   factorial();
   cin>>t;
   while(t--){
        int a,b;
        cin>>a>>b;
        cout<<C(a,b)<<endl;
   }

   return 0;
}
