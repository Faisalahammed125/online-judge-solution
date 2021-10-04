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

signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   int t,n;
   cin>>t;
   while(t--){
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i=i*10+1){
            if(i*10+1>n){
                if(n/i==10)ans+=9;
                else ans+=(n/i);
                break;
            }
            ans+=9;
        }
        cout<<ans<<endl;
   }

   return 0;
}
