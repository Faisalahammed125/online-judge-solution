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


void multiply(int res[2][2],int F[2][2]){
    int x = ((res[0][0] * F[0][0])%mod + (res[0][1] * F[1][0])%mod)%mod;
    int y = ((res[0][0] * F[0][1])%mod + (res[0][1] * F[1][1])%mod)%mod;
    int z = ((res[1][0] * F[0][0])%mod + (res[1][1] * F[1][0])%mod)%mod;
    int w = ((res[1][0] * F[0][1])%mod + (res[1][1] * F[1][1])%mod)%mod;

    res[0][0] = x;
    res[0][1] = y;
    res[1][0] = z;
    res[1][1] = w;
}

void power(int res[2][2],int n){
    int F[2][2]={{1,1},{1,0}};
    if(n<=1)return;
    power(res,n/2);
    multiply(res,res);
    if(n%2)multiply(res,F);
}

int fib(int n){
    int res[2][2]={{1,1},{1,0}};
    if(n==0)return 0;
    power(res,n-1);
    return res[0][0];
}

signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   int n;
   cin>>n;
   cout<<fib(n)<<endl;

   return 0;
}
