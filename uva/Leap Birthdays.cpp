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
   int t,d,m,y,ty,ans;
   cin>>t;
   for(int i=1;i<=t;i++){
        cin>>d>>m>>y>>ty;
        if(d==29&&m==2){
            ans=0;
            for(int p=y; p<=ty; p=p+4)
            {
                if((p%4==0 && p%100!=0) || p%400==0 )
                {
                    ans++;
                }

            }
            ans--;
        }
        else ans=ty-y;
        cout<<"Case "<<i<<": "<<ans<<endl;
   }

   return 0;
}
