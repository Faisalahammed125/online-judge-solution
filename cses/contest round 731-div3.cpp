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
const int N=5e5+5;

void solve(int t){
   int k,n,m,z=0,mx=0,x;
   cin>>k>>n>>m;
   int arr[n+2],brr[m+2];
   for(int i=0;i<n;i++)cin>>arr[i];
   for(int i=0;i<m;i++)cin>>brr[i];
   vector<int>ans;
   int i=0,j=0;
   bool f1=true,f2=true;
   for(int l=0;l<n+m;l++){
        if(arr[i]<=k&&f1){
            ans.pb(arr[i]);
            if(arr[i]==0)k++;
            i++;
            if(i>=n)f1=false;
        }
        else if(brr[j]<=k&&f2){
            ans.pb(brr[j]);
            if(brr[j]==0)k++;
            j++;
            if(j>=m)f2=false;
        }
        else{
            cout<<-1<<endl;
            return;
        }
   }
   for(int val : ans)cout<<val<<" ";
   cout<<endl;
}

signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   int T=1;
   cin>>T;
   for(int t=1;t<=T;t++){
        solve(t);
   }

   return 0;
}

