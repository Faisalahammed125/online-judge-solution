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

int fact[16];

void factorial(){
    fact[0]=fact[1]=1;
    for(int i=2;i<16;i++)fact[i]=fact[i-1]*i;
}

int nCr(int n,int r){
    return fact[n]/(fact[n-r]*fact[r]);
}
signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   factorial();
   int n,k,ev=0;
   cin>>n>>k;
   int arr[n+1];
   for(int i=0;i<n;i++){
        cin>>arr[i];
        if(!(arr[i]&1))ev++;
   }
   if(k>ev)cout<<0<<endl;
   else cout<<nCr(ev,k)<<endl;

   return 0;
}
