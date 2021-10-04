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
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        if(n==2){
            cout<<-1<<endl;
            continue;
        }
        int lim=n*n;
        int x=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(x>lim)x=2;
                cout<<x<<" ";
                x+=2;
            }
            cout<<endl;
        }
   }

   return 0;
}
