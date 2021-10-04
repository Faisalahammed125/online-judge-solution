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
   int t,n,sum;
   int arr[15];
   cin>>t;
   while(t--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>arr[i];
        cin>>sum;
        bool ok=false;
        int sz=1<<n;
        for(int mask=0;mask<sz;mask++){
            int p=0;
            for(int i=0;i<n;i++){
                int f=1<<i;
                if((f&mask)!=0)p+=arr[i];
            }
            if(p==sum){
                ok=true;
                break;
            }
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
   }

   return 0;
}
